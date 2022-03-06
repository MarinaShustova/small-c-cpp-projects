#include "Header.h"
tree *Insert(int a, tree *sprout)
{
	if (sprout == NULL)
	{
		sprout = (struct tree*)malloc(sizeof(struct tree));
		sprout->left = NULL;
		sprout->right = NULL;
		sprout->val = a;
	}
	else if (a < sprout->val)
		sprout->left = Insert(a, sprout->left);
	else
		sprout->right = Insert(a, sprout->right);
	return(sprout);
}

void print(tree *sp)
{
	if (sp == NULL) return;
	printf("%d(", sp->val);
	print(sp->left);
	print(sp->right);
	printf(")");
}