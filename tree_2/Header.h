#ifndef PROG_H
#define PROG_H
#include <stdio.h>
#include <string.h> 
#include <malloc.h> 
#define G 5
typedef struct tree {
	int val;
	struct tree *left, *right;
} tree;
struct tree *Insert(int a, struct tree *sprout);
void PrintTree(struct tree *tr);
void PrintFile(struct tree *tr1, FILE *name);
void FreeTree(struct tree *tr2);
#endif
