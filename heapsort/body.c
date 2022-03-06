#include "Header.h"
int Heapsort(int *tree, int N, char *out)
{
	FILE *outname;
	int i, j, k, flag;
	//if (N % 2 == 0)
		for (i = N - 1;i >= 1;i--)
		{
			for (j = i  / 2;j >= 0;j--)
			{
				if ((i >= j) && (i >= 2 * j + 1))
				{
					if (tree[i - j]<tree[i - 2 * j - 1])
					{
						k = tree[i - 2 * j - 1];
						tree[i - 2 * j - 1] = tree[i - j];
						tree[i - j] = k;
					}
				}
				if ((i >= j) && (i >= 2 * j + 2))
				{
					if (tree[i - j]<tree[i - 2 * j - 2])
					{
						k = tree[i - 2 * j - 2];
						tree[i - 2 * j - 2] = tree[i - j];
						tree[i - j] = k;
					}
				}
			}
		}
		if (out[0] == 's')
			for (i = 1; i < N; i++)
				printf("%d ", tree[i]);
		else if ((out[0] == '-') && (out[1] == 'o'))
		{
			outname = fopen(out + 2, "w");
			for (i = 1; i < N; i++)
				fprintf(outname, "%d ", tree[i]);
			fclose(outname);
		}
	return 0;
}