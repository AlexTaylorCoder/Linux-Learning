

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
int hashkey(char* arrPtr, int size, int mapSize) {

	int key = 0;
	for (int i = 0; i < size; i++) {
	
		key = key + (arrPtr[i] << i + 1);//expand based on map
	//	printf("%d\n Key After\n", key);
	}
	key = key % mapSize;


	printf("Hash key %d\n", key);
	return key ;
}

int add(HashMap *map, char* keyChars, int keyCharsSize, char* valChars, int valCharsSize, int wordBuffCap, int arrBuffCap)  { //cap will only matter for hashkey conflicts.
	int key = hashkey(keyChars, keyCharsSize, map -> capacity);
	ValueBuffer *buff = &map -> valueBuffer[key]; //in range of init cap
	
	if (valCharsSize > wordBuffCap) {
		printf("Char size exceeds limit, reduce by %d keyChars\n", valCharsSize - wordBuffCap);
		return 1;
	}
	

	if (buff->numEles > 1 && wordBuffCap != buff->wordBuffCap)  {
		printf("Caution you are changing the size of already allocated buffer, previous linked keys will be lost");
	} 

	
	if (buff->bufferPtr == NULL) {
		char newBuff[arrBuffCap];

		buff -> bufferPtr = &newBuff[0]; //size of capacity determined by map cap + num of eles ( assuming hash is not limiter)->
	    	buff -> arrBuffCap = arrBuffCap;

	}

	buff->wordBuffCap = wordBuffCap;

	if (buff->wordBuffCap * buff -> numEles + valCharsSize > buff -> arrBuffCap) {
		printf("Reached capacity of value assigned mem %d", buff->arrBuffCap);
		return 1;
	}

	char t = 't';
	char i = 'i';
	buff -> bufferPtr[0] = t;
	buff -> bufferPtr[1] = i;
	buff -> bufferPtr[2] = t;
	/*
	for (int i = wordBuffCap * buff -> numEles; i < valCharsSize; i++) {
		buff->bufferPtr[i] = valChars[i];
	}

	*/
	buff -> numEles = 1;

	return 0;
		
}


FixedArray get(HashMap *map, char* chars, int size) {
	int key = hashkey(chars, size, map -> capacity);

	//how to get just needed val key
	//simplified identity key, appended to beg of str
	//or n^2 iter check
	//thing is longer the str, longer needed prepend. 
	// n^2 iter check for chars if hashkey conflict
	// start simpler 
	
	ValueBuffer *vb = &map -> valueBuffer[key];

	int wordBuffCap = vb -> wordBuffCap;
	int numEles  = vb -> numEles;

	printf("init val %c\n", vb -> bufferPtr[0]);
	char *buff ;

	/*
	for (int i = 0; i < wordBuffCap * numEles; i += wordBuffCap) {
		for (int k = 0; k < wordBuffCap; k++) {
			printf("i: %d, k: %d\n", i, k);
			printf("value is %c\n", buff[i][k]);
			
			//is this garbage yes looks like it not mem addr
			str[k] = vb -> bufferPtr[k+i];
		}

	}
	*/

	printf("%d hit expected", wordBuffCap);
	FixedArray arr = { wordBuffCap, buff };

	return arr;
}	
int printArr(char *chars, int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%c", chars[i]);
	}
	printf("\n");
}

void init(int size) {
	//dynamic
	//hashkey larger must increase size of map
	//or some compression algo
	//what compression? what 
	//use length as additional mask
	//maybe shift by length? 2 ^ 10 is huge
	//but then each new bit could repr new mem maybe?
	//but then ec	char arr[100];
	char mapBuffer[size];

	ValueBuffer valueBuffer[size];
	HashMap	map = {};

	map.capacity = size;
	map.valueBuffer = &valueBuffer[0];

	char testKey[] = "1234";
	int sizeKey = sizeof(testKey) - 1;
	char testVal[] = "12345";
	int sizeVal = sizeof(testVal) - 1;

	add(&map, &testKey[0], sizeKey, &testVal[0], sizeVal, sizeVal, sizeVal * 5);
	//Each of these val buffers
	FixedArray arr = get(&map, &testKey[0], sizeKey);

	printArr(&arr.bufferPtr[0], arr.capacity);
}

int main() {
	init(500);
	return 0;
}


/*
int main() {

	char test_arr[] = {"testhashkey"};
	int test_arr_len = 12;

	int hash = hashkey(&test_arr[0], test_arr_len);
	
	printf("Hash %d\n", hash);
}
*/




