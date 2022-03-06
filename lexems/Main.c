#include "header.h"
int main(int *argc, char *argv[])
{
	int res;
	char *arr;
	int i = 0, c, out;
	FILE *info;
	char *k, *str = NULL;
	if ((argc == 2) && (!strcmp(argv[1], "?"))) 
	{
		printf("This programm can show what the string consists of and show element's position in the string.\n"
			"  %s STRING|-iFILE s|f\n"
			"Where\n  STRING is a string you should type by yourself\n"
			"  -i is a file key\n"
			"  FILE is a name of file you want to give to program\n"
			"  s is a screen key which means that result will be printed on the screen\n"
			"  f is a file key which means that result will be printed in file result.txt with adress "
			"C:\\Users\\1\\Documents\\Visual Studio 2015\\Projects\\Lexemy\n", argv[0]);
		return 5;
	}
	if (argv[2][0] == 'f')
	{
		out = 1;
		printf("Result is in file result.txt with adress C:\\Users\\1\\Documents\\Visual Studio 2015\\Projects\\Lexemy\n");
	}
	if (argv[2][0] == 's')
		out = 2;
	if (argv[1][0] == '-')
	{
		info = fopen(argv[1] + 2, "r");
		if (info == NULL)
		{
			printf("Reading error, no file");
			return -1;
		}	
		k = realloc(NULL,i+1);
		while ((c = fgetc(info)) != EOF)
		{
			i++;
			k = realloc(str, i*sizeof(int));
			if (k != NULL)
			{
				str = k;
				str[i - 1] = c;
			}
			else
			{
				printf("Memory error");
				return -1;
			}
		}
		res = lex(str, out);
		fclose(info);
		free(str);
	}
	else
	res = lex(argv[1], out);
	getch();
}
