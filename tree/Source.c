#include "Header.h"
void main(int argc, char *argv[])
{
	tree *sprout = NULL;
	int  *a = NULL;
	int i, j, res = 0;
	a = malloc(sizeof(int) * (argc));
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
			res = res * 10 + argv[i][j] - '0';
		sprout = Insert(res, sprout);
		res = 0;
	}
	print(sprout);
}