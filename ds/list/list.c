#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define CAP_EXP_RATE 2

typedef struct SizedBuffer {
	int cap;
	int *buff;
} SizedBuffer;

typedef struct List {
	int (*get)(int index, struct List *self);
	void (*add)(int val, struct List *self);
	void (*expand)(int *buff, int size, struct List *self);
	int (*remove)(int index, struct List *self);
	int (*find)(int val, struct List *self);
	int (*checkBounds) (int index, struct List *self, int (*arrOp)(int, struct List *)); 
	SizedBuffer (*remRange) (int startRange, int endRange, int step, struct List *self);
	void (*alloc) (struct List *self);
	int cap; 
	int len;

	//Could consider making this sep heap allocated var. B/c once heap will always be heap so no need to maintain var. But bool only uses 1 byte so prob not worth effort.
	bool isHeapAllocated;
	//term seq?? maybe 
	int *buff;
} List;


int printArr(int *arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d , ", arr[i]);
	}
	printf("]\n");
}

void alloc(List *self) {
	int prevCap = self -> cap;
	int nBuffSize = prevCap << CAP_EXP_RATE;

	int *nBuff = malloc(nBuffSize * sizeof(int));


	int *buff = self -> buff;
	for (int i = 0; i < prevCap; i++) {
		nBuff[i] = buff[i];
	}

	if (self -> isHeapAllocated == true) {
		free(buff);
	} else {
	       self -> isHeapAllocated = true;
	}

	self -> buff = nBuff;
	self -> cap = nBuffSize;
}
int checkBounds(int index, List *self, int (*arrOp)(int, List *)) {
	int cap = self -> cap;
	if (index > cap) {
		printf("%d index cannot be larger than list capacity %d\n", index, cap);	
		return -1;
	}

	return arrOp(index, self);
}

void add(int val, List *self) {

	int len = self -> len;
	if (self -> cap <= len) {
	       alloc(self);
	}


	self -> buff[len] = val;
	self -> len += 1;
}

void expand(int *buff, int size, List *self) {
	int len = self -> len;

	int newLen = len + size;
	if (self -> cap <= newLen) {
		int *prevBuff = self -> buff;

		int newBuffSize = newLen << CAP_EXP_RATE;
		int *nBuff = malloc(newBuffSize * sizeof(int));
		for (int i = 0; i < len; i++) {
			nBuff[i] = prevBuff[i];
		}

		if (self -> isHeapAllocated == true) {
			free(prevBuff);
		} else {
		       self -> isHeapAllocated = true;
		}
		
		self -> buff = nBuff;
		self -> cap = newBuffSize;
	}

	for (int i = 0; i < size; i++) {
		self->buff[len+i] = buff[i];
	}
	self -> len += size;
}

int get(int index, List *self) {
	return self -> buff[index];
}

SizedBuffer remRange(int startRange, int endRange, int step, List *self) {

	int *buff = self -> buff;
	if (startRange > endRange) {
		printf("Start range %d cannot be greater than End Range %d", startRange, endRange);
		SizedBuffer buff = {0, NULL}; 
		return buff;
		}

	int cap = self -> cap;
	if (step > cap) {
		printf("Steps %d greater than cap %d", step, cap);
		SizedBuffer sBuff = {0, NULL}; 
		return sBuff;
		} 

	int indSize = (startRange - endRange) / step;

	int removed[indSize];
	int count = 0;
	for ( int i = startRange; i < endRange; i+=step) {
		buff[i] = buff[i + 1];
		removed[count] = i;
		count += 1;
	}

	if (indSize <= 0) {
		SizedBuffer buff = {0, NULL}; 
		return buff;
	}

	self -> len -= indSize;
	SizedBuffer sBuff = {indSize, &removed[0]};
	return sBuff;
}
int rem(int index, List *self) {
	//Buff size will never reduce, just eles shifted
	

	int *buff = self -> buff;
	for ( int i = index; i < self -> len; i+=1) {
		buff[i] = buff[i + 1];
	}

	self -> len -= 1;

	return -1;
}

int find(int val, List *self) {
	for (int i = 0; i <= self -> len; i++) {
		if (self -> buff[i] == val) {
			return i;
		}
	}
	return -1;
}



int main() {
	List list;
	list.add = &add;
	list.get = &get;
	list.remove = &rem;
	list.find = &find;
	list.checkBounds = &checkBounds;
	list.remRange = &remRange;
	list.alloc = &alloc; 
	list.expand = &expand;

	int arr[] = {1,2,3,4,5}; //32 bit int arr
	int startingCap = sizeof(arr) / sizeof(int);

	list.cap = startingCap;
	list.len = startingCap;
	list.buff = &arr[0];
	list.isHeapAllocated = false;

	printArr(&list.buff[0], list.len);
	// int isRem = list.checkBounds(foundInd, &list, &rem); 

	SizedBuffer sizedBuffer = list.remRange(0, 2, 1, &list);

	printArr(&list.buff[0], list.cap);

	list.add(105, &list);
	list.add(105, &list);
	list.add(105, &list);
	list.add(105, &list);
	list.add(105, &list);
	list.add(105, &list);

	int buff[] = {98,99,100,101,102};
	

	list.remove(list.find(105, &list), &list);
	list.expand(&buff[0], sizeof(buff) / sizeof(int), &list);

	//now need to do that thing with byte maybe
	printArr(&list.buff[0], list.len);
	return 0;
}
