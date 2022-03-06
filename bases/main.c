#include "Header.h"
int main(int argc, char *argv[])
{
	int result;
	char *o1, *o2, *d1;
	char str1[100], str2[100], str3[100];
	FILE *parametres;
	if (argc != 4)
	{
		if (argv[1][0] == '-')
		{
			parametres = fopen(argv[1] + 2, "r");
			if (parametres == NULL)
			{
				printf("Reading error, no file");
				return -1;
			}
				o1 = fgets(str1, 100, parametres);
				if (o1 == NULL)
					if (feof(parametres) == 0)
					{
						printf("Reading error in file");
						return -1;
					}
				/*if ((str1[99] != 0) && (str1[100] != '\n'))
				{
					printf("Too much figures in number");
					return -1;
				} */
				o2 = fgets(str2, 100, parametres);
				if (o2 == NULL)
					if (feof(parametres) == 0)
					{
						printf("Reading error in file");
						return -1;
					}
				/*if ((str2[99] != 0) && (str2[100] != '\n'))
				{
					printf("Too much figures in number");
					return -1;
				}*/
				d1 = fgets(str3, 100, parametres);
				if (d1 == NULL)
					if (feof(parametres) == 0)
					{
						printf("Reading error in file");
						return -1;
					}
				/*if ((str3[99] != 0) && (str3[100] != '\n'))
				{
					printf("Too much figures in number");
					return -1;
				}*/
				fclose(parametres);
		}
		if ((argc == 2) && (!strcmp(argv[1], "?")))
		{
			printf( "This programm can convert a number, given in one base (b1) into number in second base (b2).\n"
					"You should type your base1 base2 number, where\n"
					"base1 is the first base in which your number is given.\n"
					"base2 is the second base which you want to convert your number in.\n"
					"number is a number you want to convert itself.\n"
					"For example\n name.exe 10 2 2 \n result is \"10\"\n"
					"Number shouldn't consist of more than 100 figures.");
			return 5;
		}
		else if ((argv[1][0] != '-') && !((argc == 2) && (!strcmp(argv[1], "?"))))
		{
			printf("Incorrect strings\n");
			getchar();
			return -1;
		}
	}
	o1 = argv[1];
	o2 = argv[2];
	d1 = argv[3];
	result = systems(o1, o2, d1);
	printf("Result code is %d\n", result);
	getch();
	return 0;
}