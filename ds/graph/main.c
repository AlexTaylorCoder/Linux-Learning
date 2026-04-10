#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "graph.h"

void genterr(Terrain *t, int size) {
	for (int i = 0; i < size; i++) {
		t[i].weight = rand();
	}
}

void genterrgrad(Terrain *t, int size) {
	//sort by vec
	//apply grad
	//
	for (int i = 0; i < size; i++) {
		t[i].weight = rand();
	}
}


void mergesort(Terrain *t, int l, int r) {
	//merge sort? Quick sort, etc. pivot sort
	mid = (l + r) / 2;
	
	if (l == r) {
		printf("testt");	
	}
	left = mergesort(t, l, mid);
	right = mergesort(t, mid + 1, r);
		
}
//Grad could be formed from 
int main() {
	Node n1 = {NULL, 0, 0}; //leaf
	Node n2 = {NULL, 0, 0}; //leaf 
	Node n3 = {NULL, 0, 0}; //leaf
			       
	//Terrain t1;
	//Terrain t2;
	
	Terrain terrains[] = {
		{},
		{}
	};

	srand(time(NULL));
	genterr(&terrains[0], sizeof(terrains)  / sizeof(terrains[0]));

	Node nodes[] = {n1, n2, n3};
	Node parent = {&nodes[0], sizeof(nodes), 99};


	return 1;
}


