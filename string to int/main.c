#include "header.h" 

int main(int argc, char *argv[])
{
	int res;
	int value;
	if (argc != 2)
	{
		getchar();
		return 5;
	}
	else
	{
		res = StrToInt(argv[1], &value);
		if (res == 0)
			printf("Success! %d\n", value);
		else
			printf("Not successful. Error code is %d\n", res);
		getchar();
		return res;
	}
	
	return 0;
}