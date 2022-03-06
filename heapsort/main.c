#include "Header.h"
int main(int argc, char *argv[])
{
	FILE *info;
	int  *a = NULL;
	int i, r, num, total_l = 0, curr_l = 0, out;
	char *k, *b = NULL;
	if ((argc == 2) && (!strcmp(argv[1], "?")))
	{
		printf("This programm can sort given array in ascending order.\n"
			"  %s a1 ... aN|-iFILE1 s|-oFILE2\n"
			"Where\n  a1 ... aN is an array you should type by yourself\n"
			"  -i is an input file key\n"
			"  FILE1 is a name of file you want to give to program\n"
			"  s is a screen key which means that result will be printed on the screen\n"
			"  -o is an output file key which means that result will be printed in file\n"
			"  FILE2 is a name of file in which result will be printed\n", argv[0]);
		return 0;
	}
	if ((argv[2][0] == '-') && (argv[2][1] == 'o'))
		printf("Result is printed in file %s with adress C:\\Users\\1\\Documents\\Visual Studio 2015\\Projects\\Heapsort\n", argv[2] + 2);
	if ((argv[1][0] == '-') && (argv[1][1] == 'i'))
	{
		info = fopen(argv[1] + 2, "r");
		if (info == NULL)
		{
			printf("Reading error, no file");
			return -1;
		}
		while (1)
		{
			fscanf(info, "%d", &num);
			if (feof(info))
			{
				fclose(info);
				break;
			}
			if (curr_l >= total_l)
			{
				total_l += G;
				a = (int *)realloc(a, total_l*sizeof(int));
			}
			a[curr_l] = num;
			curr_l++;
		}
		//a = (int *)realloc(a, curr_l+1);
		r = Heapsort(a, curr_l + 1, argv[2]);
		free(a);
		return 0;
	}
	else
	{
		a = malloc(sizeof(int) * (argc));
		for (i = 0; i < argc - 1; i++)
		{
			/*for (t = 0; argv[i+1][t] != '\0'; t++)
			{
				a[i] = a[i] * 10 + argv[i+1][t] - '0';
			}*/
			if (argv[i + 1][2] != '\0')
			{
				a[i] = (argv[i + 1][0] - '0') * 100 + (argv[i + 1][1] - '0')*10 + argv[i + 1][2] - '0';
			}
			if (argv[i + 1][1] != '\0')
			{
				a[i] = (argv[i + 1][0] - '0') * 10 + argv[i + 1][1] - '0';
			}
			else
			{
				a[i] = *argv[i + 1] - '0';
			}
		}
		r = Heapsort(a, argc, argv[2]);
		free(a);
		return 0;
	}
}