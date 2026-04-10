#include <stdlib.h>


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
	void (*alloc) (struct List *self, int fixedExpRate);
	int cap; 
	int len;

	//Could consider making this sep heap allocated var. B/c once heap will always be heap so no need to maintain var. But bool only uses 1 byte so prob not worth effort.
	bool isHeapAllocated;
	//term seq?? maybe 
	int *buff;
} List;
void init(List *list);
