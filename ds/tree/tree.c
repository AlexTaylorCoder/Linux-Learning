#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

void printarr(int *vals, int len) {
  printf("[");
  for (int i = 0; i < len; i++) {
    if (i % 10 == 0) printf("\n");
    printf(" %d, ", vals[i]);
  }

  printf("]");
}

void build_tree(tree *self, int *vals, int len) {

  printf("len %d\n", len);
  //only l and r
  int stack[len*2]; 
  int mid[len*2];

  //rev order for now ig
  int l = 0;
  int r = len - 1;

  // [ 1, 2, 3, 4, 5, 6, 7, 8, 9]
  int mid = (l + r) / 2; //floors
  int smid = mid;
  int i = 0;
  while (l < mid && r > mid) {
    int mid = (l + r) / 2; //floors
    
  
    l = (mid - l + 1) / 2;
    r = smid + (r - mid) / 2;

    i+=2;
    stack[i] = vals[l];
    stack[i+1] = vals[r];
    
    mid[i] = l;
    mid[1+1] = r;

    printf("left %d, mid %d, right %d", l, mid, r);
  }
  printarr(stack, len);
}


int main() {
  struct tree t; 
  int vals[] = {1,2,3,4,5,6,7,8};

  build_tree(&t, vals, sizeof(vals) / sizeof(int));
  return 1;
}
