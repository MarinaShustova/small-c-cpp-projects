#include "header.h" 
int StrToInt(char *s, int *result)
{
	int sign = 1;
	/*int chet = 0;*/
	int i = 0;
	unsigned int p = 0;
	int n;
	n = 0;
	if (!s || !*s)
	{
		i = ERR_NOSTR;
		return i;
	}
	while (*s == ' ')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
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
				i = ERR_OVERFL;
				return i;
			}
	}
	while (*s == ' ')
		s++;
	if (*s != 0)
	{
		i = ERR_INCORRECT;
		return i;
	}
	/*if (chet == 0)
	{
		i = ERR_INCORRECT;
		return i;
	}*/
	i = 0;
	if (sign == -1)
	*result = n*sign;
	return i;
}