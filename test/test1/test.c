#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "list.h"

#define CAP_EXP_RATE 2

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
