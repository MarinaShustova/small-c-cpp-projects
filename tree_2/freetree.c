#include "Header.h"
void FreeTree(struct tree *sprout)
{
	if (sprout)
	{
		FreeTree(sprout->left);
		FreeTree(sprout->right);
		free(sprout);
	}
}