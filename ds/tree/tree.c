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


void traverse(node *n) {
  node *l_node = n -> left;
  node *r_node = n -> right;

  if (l_node == NULL && r_node == NULL) {
    return;
  }
  if (r_node == NULL) {
    printf("LeftNode value %d", l_node->val);
    return;
  }
  if (l_node == NULL) {
    printf("Right Node value %d", r_node->val);
    return;
  }

    printf("LeftNode value %d", l_node->val);
    printf("Left Node value %d", r_node->val);

    traverse(l_node);
    traverse(r_node);

    return;
}

node build_tree(int vals[], int l, int r) {
  if (l == r) {
    node node = {NULL, NULL, vals[l]};
    return node;
  }

  int mid = (l + r) / 2; //floors
  printf("left %d, mid %d, right %d\n", l, mid, r);

  node l_node = build_tree(vals, l, mid);
  node r_node = build_tree(vals, mid + 1, r);

  node node = {&l_node, &r_node, vals[mid]};
  return node;
}
//void build_tree(tree *self, int *vals, int len) {
//
//  printf("len %d\n", len);
//  //only l and r
//  int queue[len]; 
//
//  //rev order for now ig
//  int l = 0;
//  int r = len - 1;
//
//  // [ 1, 2, 3, 4, 5, 6, 7, 8, 9]
//  int mid = (l + r) / 2; //floors
//  int smid = mid;
//  int i = 0;
//
//  tree -> head = { { val=vals[mid]}};
//  while (queue[0] != -1 && queue[len-1] != -1) {
//    int ele = queue[i];
//    while (l != mid && r != mid) {
//      int mid = (l + r) / 2; //floors
//      
//    
//      l = (mid - l + 1) / 2;
//      r = smid + (r - mid) / 2;
//
//      self
//      i+=2;
//      stack[i] = vals[l];
//      stack[i+1] = vals[r];
//      
//      mid[i] = l;
//      mid[1+1] = r;
//
//    }
//  printarr(stack, len);
//}
//void printtree(node &node, int size) {
  //queue = [size];
//
  //while queue() //iter over queue and add based
//
//}

int main() {
  struct tree t; 
  int vals[] = {1,2,3,4,5,6,7,8};

  int l = 0;
  int r = sizeof(vals) / sizeof(int) - 1;

  node node = build_tree(vals, l, r);
  traverse(&node);
  return 1;
}
