#include"Header.h"
int systems(char *b1, char *b2, char *num1, char *massive, int *xx)
{
	int j, p = -1, v1 = 0, v2 = 0, r1 = 0, r2 = 0, i, L = 100, x;
	char y;
	char *k;
	char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if ((!b1 || !*b1)|| (!b2 || !*b2)|| (!*num1 || !*num1))
	{
		j = ERR_NOSTR;
		printf("You didn't write any string(s)");
		return j;
	}
	while (*b1 != '\0')
	{
		if (isdigit(*b1) != 0)
		{
			r1 = r1 * 10 + (*b1 - '0');
			b1++;
		}
		else
		{
			j = ERR_BASE;
			printf("Symbol(s) in your first base is(are) incorrect. These symbol(s) is(are) '%c'\n", *b1);
			return j;
		}
	}	
	if (r1 > 36)
	{
		printf("Your first base is too big. Program can't work with bases which are greater than 36."
			   "Your base is %d \n", r1);
		j = ERR_BIGBASE;
		return j;
	}
	if (r1 == 0)
	{
		j = ERR_BASE;
		printf("Incorrect 0 base1");
		return j;
	}
	while (*b2 != '\0')
	{
		if (isdigit(*b2) != 0)
		{
			r2 = r2 * 10 + (*b2 - '0');
			b2++;
		}
		else
		{
			j = ERR_BASE;
			printf("Symbol(s) in your second base is(are) incorrect. These symbol(s) is(are) '%c'\n", *b2);
			return j;
		}
	}
	if (r2 > 36)
	{
		printf("Your second base is too big.Program can't work with bases which are greater than 36."
			   "Your base is %d \n", r2);
		j = ERR_BIGBASE;
		return j;
	}
	if (r2 == 0)
	{
		j = ERR_BASE;
		printf("Incorrect 0 base2");
		return j;
	}
	while (*num1 != '\0')
	{
		if (*num1 == ' ')
			num1++;
		if (((*num1 >= '0') && (*num1 <= '9')) || ((*num1 >= 'A') && (*num1 <= 'Z')))
		{
			if (isdigit(*num1) != 0)
			{
				if (p == -1)
					p = p + 1;
				p = p * r1 + (*num1 - '0');
				if ((p%10) >= r1)
				{
					j = ERR_BIGNUM;
					printf("Figures in your number shouldn't be greater then %d\n", r1-1);
					return j;
				}
				num1++;
			}
			if (isalpha(*num1) != 0)
			{
				if (r1 <= 10)
				{
					j = ERR_BIGNUM;
					printf("You can't use letters with %d base.\n", r1);
					return j;
				}
				else
					if (*num1 <= digits[r1-1])
						{
							p = p * r1 + (*num1 - 'A' + 10);
							num1++;
						}
					else
					{
						j = ERR_BIGNUM;
						printf("You can't use letters which are greater than %c with base %d.\n", digits[r1-1], r1);
						return j;
					}
			}
		}
		else
		{
			j = ERR_INP;
			printf("You use wrong register \n");
			return j;
		}
	}
	k = malloc(L);
	if (p == 0)
	{
		printf("New number is %d", p);
		return 0;
	}
	for (i = 0; p != 0 ;i++)
	{
		if (i == L - 1)
		{
			L *= 2;
			realloc(k, L);
		}
		k[i] = digits[p%r2];
		p = p / r2;
		x = i;
	}
	for (i = 0; i <= (x + 1) % 2; i++)
	{
		y = k[i];
		k[i] = k[x - i];
		k[x - i] = y;
	}
	printf("New number is ");
	for (i = 0; i <= x; i++)
		{
			printf("%c", k[i]);
		}
	printf("\n");
	free(k);
	j = NORMAL;
	return j;
}