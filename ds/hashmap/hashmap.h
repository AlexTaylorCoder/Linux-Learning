#include <stdbool.h>

typedef struct Pair {
	int key;
	int value;
	bool isempty;	
	struct Pair *next;
} Pair;
// typedef struct Value {
// 	int cap;
// 	Pair *pairs; //k v pairs needed in case dupe hash
// } Value;

typedef struct MapProps {
	int cap;
	Pair *buff;
} MapProps;



//user interface
typedef struct Map {
	int (*get)(MapProps *props, int key);
	int (*add)(MapProps *props, int key, int val);
	void (*rem)(MapProps *props, int key);
	int (*rem_val)(MapProps *props, int key, int val);
	int (*hashkey)(MapProps *props, int val);
} Map;


	
