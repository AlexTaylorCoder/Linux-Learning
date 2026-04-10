#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

#include "hashmap.h"

#define INIT_CAP 10
//return is index
int hashkey(MapProps *props, int key) {
	//hashing strat????
	
	// good thing is with int should just need to fit into arr
	int cap = props -> cap;

	return key & (cap - 1); //Will map hashkey to cap bitmask
}

int get_index(MapProps *props, int key) {
		int hash = hashkey(props, key);

		int cap = props -> cap;
		return hash % cap;
}

//  dont even need linked list for basic int maps b/c dont need hashing
//  so instead impl simple linked hashmap. which can contain dupe keys
int get_first_from_linked(Pair *p, int key) {
	Pair *head = p;
	while (head != NULL) {
		if (head -> key = key) {
			return head -> value;
		}
		head -> next;
	}
	printf("Matching unhashed key not found, something wrong with impl");
	exit(1);
}

int get(MapProps *props, int key) {

	Pair *pairbuff = &props -> buff[get_index(props, key)];//ptr to val
						    
	if (pairbuff -> isempty == true) { 
		printf("key %d not found", key);
		//can either pass responsbiilty to user
		//or use wrapper obj; 
		exit(1);
	} 

	return get_first_from_linked(pairbuff, key); //
	
}

void add_to_linked(Pair *p, Pair *newP) {
	Pair *head = p;

	while (head -> next != NULL && head -> next -> isempty == false) {
		head = head -> next;
	}

	head -> next = newP;
}
//type 
int add(MapProps *props,int key, int val) {
	int hash = hashkey(props, key);

	int cap = props -> cap;

	// always within hashmap buff
	Pair *pairbuff = &props -> buff[get_index(props,key)];//ptr to val
					//
					//
					//

	if (pairbuff -> isempty == true) {
		pairbuff -> isempty = false;
		pairbuff -> key = key;
		pairbuff -> value = val;
		return 1;
	} else {

		Pair p = {key, val, false, NULL};
		Pair *nBuff = malloc(sizeof(Pair));
nBuff 
		add_to_linked(pairbuff, &p);
		return 0;
		//CONS
		//	//o(n) on hash collision
		//linked struct makes more sense
		// b/c hashmap collisions are travresed much
	}
}

int rem_from_linked(Pair *p, int val) {
	Pair *head = p;
	while (head -> next != NULL) {
		if (head -> next -> value = val) {

			Pair *newNext = head -> next -> next;
			
			head -> next = NULL; //lose next which is val to rem
			//TODO if heap allocated need to also free mem.
			head -> next = newNext; //assign to node after

			return 0;
	}
		head = head -> next;
	}
	return -1;
}

void rem(MapProps *props,int key) {
	int ind = get_index(props,key);

	Pair *pairbuff = &props -> buff[get_index(props,key)];//ptr to val
	
	pairbuff -> isempty = true;
}

int rem_val(MapProps *props, int key, int val) {
	int ind = get_index(props,key);

	Pair *pairbuff = &props -> buff[get_index(props,key)];//ptr to val

	return rem_from_linked(pairbuff, val);
}


int main() {
	Pair p[INIT_CAP];

	for (int i = 0; i < INIT_CAP; i++) {
		p[i].isempty = true;
	}

	MapProps props = {
		INIT_CAP,
		&p[0]
	};

	Map map;
	map.get = &get;
	map.add = &add;
	map.rem = &rem;
	map.rem_val = &rem_val;

	map.add(&props, 1, 10);
	map.add(&props, 1, 100);

	map.add(&props, 2, 20);

	int val = map.get(&props, 1); 
	int val2 = map.get(&props, 2); 

	printf("val %d\n", val);
	printf("val 2 %d\n", val2);

	// map.rem(&props, 2);
	// int val2t = map.get(&props, 2); //should throw
	// printf("val 2 %d\n", val2t);


	int valrem = map.rem_val(&props, 1, 100);
	printf("val 100 should be 10 now %d", valrem);
	return 1;
}

int test() {
  int pp = 24;
int tt = 12125;
    return pp + tt;
}
