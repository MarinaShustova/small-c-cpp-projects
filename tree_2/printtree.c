#include "Header.h"
void PrintTree(struct tree *tr)
{
		if (!tr)
			return;
		PrintTree(tr->left);
		printf("%d\n", tr->val);
		PrintTree(tr->right);
}

void PrintInFile(struct tree *tr, FILE *out)
{
	{
		if (!tr)
			return;
		PrintInFile(tr->left, out);
		fprintf(out, "%d\n", tr->val);
		PrintInFile(tr->right, out);
	}
}