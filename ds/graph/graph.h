
//start with interface
//

//What type of graph should Be createdc??????
typedef struct Vec {
	int x;
	int y;
} Vec;
typedef struct Terrain {
	float weight;
} Terrain;

typedef struct Graph {
	void (*add) (struct Graph *self, int val);
	int (*rem) (struct Graph *self);
	int (*find) (struct Graph *self, int val);
	int (*get) (struct Graph *self, int idx);
} Graph;


typedef struct Node {
	struct Node *children;
	int sizechildren;
	int val;
	Vec vec; //Used to map to pos
} Node;


