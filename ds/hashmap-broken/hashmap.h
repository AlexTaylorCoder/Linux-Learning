
//test
// Hashmap
   // Turn into int
   // shift bytes 
   // 32 int
   // 2^32 
   // hash = asci val + index val
//Could use linked list structure
//ORRRRR if chars dont change can use single arr buff
// Could alocate *n capacity to allow
typedef struct {
     	int capacity;
	char *bufferPtr;	
} FixedArray; 

typedef struct {
	int wordBuffCap;
	int arrBuffCap;
	int numEles;
	char *bufferPtr;
} ValueBuffer;

typedef struct {
	int capacity;
	ValueBuffer *valueBuffer;
} HashMap;

	
