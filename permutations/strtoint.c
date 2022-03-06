#include "header.h";
int StrToInt(char *s)
{
	int j;
	/*int chet = 0;*/
	int i = 0;
	unsigned int p = 0;
	int n;
	n = 0;
	if (!s || !*s)
		return -1;
		while (*s == ' ')
			s++;
		if (*s == '-')
		{
			printf("Only positive numbers are allowed. Your number is %s\n", s);
			return -1;
		}
		else if (*s == '+')
			s++;
		while (*s >= '0' && *s <= '9')
		{
			p = n;
			n = n * 10 + *s - '0';
			/*chet++;*/
			s++;
			if (p > n)
			{
				printf("oooh");
				return -1;
			}
		}
		/*while (*s == ' ')
			s++;
		if (*s != 0)
			return -1;*/
		/*if (chet == 0)
		{
		i = ERR_INCORRECT;
		return i;
		}*/
		return n;
}