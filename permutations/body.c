#include "header.h";
int perest(int N, char *outname)
{
	FILE *output = NULL;
	int i, j, L, R, t, chet = 1, f = 1, flag = 0;
	int *a;
	a = malloc(N * sizeof(int)+1);
	for (i = 0; i < N; i++)
		a[i] = i+1;
	if (outname[0] == 's')
	{
		flag = 1;
		printf("%d\n", N);
		for (i = 0; i < N; i++)
			printf("%d", a[i]);
		printf("\n");
	}
	else if ((outname[0] == '-') && (outname[1] == 'o'))
	{
		flag = 2;
		output = fopen(outname + 2,"w");
		fprintf(output,"%d\n", N);
		for (i = 0; i < N; i++)
			fprintf(output,"%d", a[i]);
		fprintf(output, "\n");
	}
	else
	{
		printf("Incorrect second arguement.\n");
		return 0;
	}
	/*if (N == 0)
		printf("No parametres");*/
	for (i = 0; i < N; i++)
		f = f*(N - i);
	while (chet < f)
	{
		for (L = N - 2;L >= 0;L--)
			if (a[L] < a[L + 1])
				break;
		for (j = N - 1;j > L;j--)
			if (a[j] > a[L])
			{
				R = j;
				break;
			}
		t = a[L];
		a[L] = a[R];
		a[R] = t;
		for (i = L + 1, j = N - 1; i <= j; i++, j--)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		if (flag == 1)
		{
			for (i = 0; i < N; i++)
				printf("%d", a[i]);
			printf("\n");
			chet++;
		}
		if (flag == 2)
		{
			for (i = 0; i < N; i++)
				fprintf(output, "%d", a[i]);
			fprintf(output, "\n");
			chet++;
		}
	}
	if (output != NULL)
		fclose(output);
	return 0;
}