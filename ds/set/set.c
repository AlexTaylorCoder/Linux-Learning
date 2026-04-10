#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// Start simple with mem managment. Use heap alloc initially, then can switch to starting stack alloc -> heap

//use term seq also is standard
//account for collisions same as map
typedef struct pair {
  char *k,
  char *v
} pair;

typedef struct linkedbuff {
  Pair *p,
  int cap,
  int size,
} linkedbuff;


int hash(char *chars, int size) {

  int h = 0;

  //char is 1 byte 2^3
  //max should be 64 bit 2^64
  //which means hash needs to ideally be evenly distributed

  
  //char exp to 2^64 / ( 2^3 * num chars)
  //so chars can be shifted over this # times I think

  
  
  for (int i = 0; i < size; i++) {
    chars[i] + i >> 64   
  }
}

