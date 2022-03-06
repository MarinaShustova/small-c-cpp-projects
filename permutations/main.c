#include "header.h";
int main(int argc, char *argv[])
{
	int N, i;
	int j = 0, c;
	FILE *info;
	char *k, *str = NULL;
	if ((argc == 2) && (!strcmp(argv[1], "?")))
	{
		printf("This programm can print all permutations of 1...N row where N is a number, given by user.\n"
			"  %s N|-iFILE1 s|-oFILE2\n"
			"Where\n  N is a number you should type by yourself\n"
			"  -i is an input file key\n"
			"  FILE1 is a name of file you want to give to program\n"
			"  s is a screen key which means that result will be printed on the screen\n"
			"  -o is an output file key which means that result will be printed in file\n"
			"  FILE2 is a name of file in which result will be printed\n", argv[0]);
		return 0;
	}
	if ((argc < 3) && (argv[1][0] != '?'))
	{
		printf("You didn't give enough parametres. You gave only %s ", argv[0]);
		if (argv[1])
			printf("%s\nPlease, watch Help.\nTo see Help print %s ?\n", argv[1], argv[0]);
		else
			printf("\nPlease, watch Help.\nTo see Help print %s ?\n", argv[0]);
		return 0;
	}
	if (argc > 3)
	{
		printf("You gave too much parametres. Please, watch Help.\nTo see Help print %s ?\n", argv[0]);
		return 0;
	}
	if ((argv[2][0] == '-') && (argv[2][1] == 'o'))
		printf("Result is printed in file %s with adress C:\\Users\\1\\Documents\\Visual Studio 2015\\Projects\\seventh\n", argv[2]+2);
	if ((argv[1][0] == '-') && (argv[1][1] == 'i'))
	{
		info = fopen(argv[1] + 2, "r");
		if (info == NULL)
		{
			printf("Reading error, no file");
			return -1;
		}
		k = realloc(NULL, j + 1);
		while ((c = fgetc(info)) != EOF)
		{
			j++;
			k = realloc(str, j * sizeof(int));
			if (k != NULL)
			{
				str = k;
				str[j - 1] = c;
			}
			else
			{
				printf("Memory error");
				return -1;
			}
		}
		N = StrToInt(str);
		i = perest(N, argv[2]);
		fclose(info);
		free(str);
		return 0;
	}
	else
	{
		N = StrToInt(argv[1]);
		if (N != -1)
			i = perest(N, argv[2]);
		return 0;
	}
}