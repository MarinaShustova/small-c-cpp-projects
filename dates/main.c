#include "header.h" 

int main(int argc, char *argv[])
{
	int end;
	if (argc != 3)
	{
		if ((argc == 2) && (!strcmp(argv[1], "-?")))
		{
			printf("This programm counts days between two dates."
				   "Dates should be given in DD/MM/YYYY form."
				   "Order of dates isn't important.\n");
			return 12;
		}
		printf("Incorrect strings\n");
		getchar();
		return -1;
	}
	else
	{
		end = second_step(argv[1], argv[2]);
		if (end != -1)
		printf("Result is %d\n", end);
	}
	
	getchar();
	return 0;
}