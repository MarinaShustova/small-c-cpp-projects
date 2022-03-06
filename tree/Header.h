#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
	int val;
	struct tree *left, *right;
} tree;
tree *Insert(int a, tree *sprout);
void print(tree *sp);