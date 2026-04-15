
typedef struct node {
  struct node *left;
  struct node *right;
  int val;
} node;

typedef struct tree {
  struct node *head;
} tree;
