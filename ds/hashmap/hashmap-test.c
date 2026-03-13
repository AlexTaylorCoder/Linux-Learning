#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int hashkey(char* arrPtr, int size);

bool arrEquals(char* ptr1, char* ptr2, int len1, int len2) {
	if (len1 != len2) { return false; }
	for (int i = 0; i < len1; ++i) {
		if (ptr1[i] != ptr2[i]) {
			return false;
		}
	}

	return true;
}

void printPass() {
	printf("Test Passed\n\n");
}
void printFail() {
	printf("Test Failed\n\n");
}
int hashNotEquals(char* ptr1, char* ptr2, int size1, int size2) {

	int key1 = hashkey(ptr1, size1);
	int key2 = hashkey(ptr2, size2);

	printf("Hash Not Equals: ");
	printf("%d VS %d\n", key1, key2);

	if (key1 != key2) {
		printPass();
		return 0;
	} else {
		printFail();
		return 1;
	}
}
int hashEquals(char* ptr1, char* ptr2, int size1, int size2) {
	int key1 = hashkey(ptr1, size1);
	int key2 = hashkey(ptr2, size2);

	printf("Hash Equals: ");
	printf("%d VS %d\n", key1, key2);

	if (key1 == key2) {
		printPass();
		return 0;
	} else {
		printFail();
		return 1;
	}
}
int check_same_chars_diff_order() {
	char test_arr[] = {"estt"};

	char test_arr_2[] = {"test"};

	int size1 = sizeof(test_arr) - 1;
	int size2 = sizeof(test_arr_2) - 1;

	int sucess = hashNotEquals(&test_arr[0], &test_arr_2[0], size1, size2);

	printf("Assertion: Same Chars Diff Order\n\n");

	return sucess;
}
int check_unique_length_neq() {
	char test_arr[] = {"testtest"};

	char test_arr_2[] = {"test"};

	int size1 = sizeof(test_arr) - 1;
	int size2 = sizeof(test_arr_2) - 1;

	int sucess = hashNotEquals(&test_arr[0], &test_arr_2[0], size1, size2);

	printf("Assertion: Unique Length\n\n");
	return sucess;
}
int check_dupe() {
	char test_arr[] = {"test"};

	char test_arr_2[] = {"test"};

	int size1 = sizeof(test_arr) - 1;
	int size2 = sizeof(test_arr_2) - 1;


	int sucess = hashEquals(&test_arr[0], &test_arr_2[0], size1, size2);
	printf("Assertion: Same chars same hash");
	return sucess;
}



int main() {
	int fail = 0;
	int totalTests = 3;

	fail = fail + check_dupe();
	fail = fail + check_unique_length_neq();
	fail = fail + check_same_chars_diff_order();

	printf("\n%d Tests Failed\n", fail);
	printf("%d Tests Suceeded\n", totalTests - fail);

	return 0;
}

