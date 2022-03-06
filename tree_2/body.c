#include "Header.h"
struct tree *Insert(int a, struct tree *sprout)
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