#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int printArr(int *arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d , ", arr[i]);
	}
	printf("]\n");
}
int main() {
	int arr[] = {1,2,3,4,5}; //32 bit int arr
	int startingCap = sizeof(arr) / sizeof(int);

	List list;
	
	init(&list);

	list . cap = startingCap;
	list . len = startingCap;
	list . buff = &arr[0];
	list . isHeapAllocated = false;

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
