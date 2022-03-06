#include "header.h" 

int is_leap(unsigned int year) {
	int t;
	t = (((year) % 4 == 0) && (((year) % 100 != 0) || ((year) % 400 == 0)));
	return t;
}

int ymd_to_days(char *str, int *number)
{
	int i, vis;
	if (!str || !*str)
	{
		i = ERR_NOSTR;
		return i;
	}
	static int days_before_month[] = {
		0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
	};
	struct dates dx;
	if (isdigit(str[0]) && isdigit(str[1]))
	{
		dx.d = (str[0] - '0') * 10 + (str[1] - '0');
		if (dx.d < 1 || dx.d > 31)
		{
			i = ERR_INCD;
			printf("Incorrect date. Day's number can't be less than 1 or greater than 31. Your day is %d. Error code is %d\n", dx.d, i);
			return i;
		}
	}
		else
		{
			i = ERR_NODIG;
			printf("Your date symbol is incorrect. Error code is %d\n", i);
		}
if (isdigit(str[3]) && isdigit(str[4]))
{
	dx.m = (str[3] - '0') * 10 + (str[4] - '0');
	if (dx.m < 1 || dx.m > 12)
	{
		i = ERR_INCM;
		printf("Incorrect date. Month's number can't be less than 1 or greater than 12. Your month is %d. Error code is %d\n", dx.m, i);
		return i;
	}
}
		else
		{
			i = ERR_NODIG;
			printf("Your date symbol is incorrect. Error code is %d\n", i);
		}
	if (isdigit(str[6]) && isdigit(str[7]) && isdigit(str[8]) && isdigit(str[9]))
	{
		dx.y = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');
		if (dx.y < 0 || dx.d > 9999)
		{
			i = ERR_INCY;
			printf("Incorrect date. Year's number can't be less than 0 or greater than 9999. Your year is %d. Error code is %d\n", dx.y, i);
			return i;
		}
	}
		else
		{
			i = ERR_NODIG;
			printf("Your date symbol is incorrect. Error code is %d\n", i);
		}
	vis = is_leap(dx.y);
	if (((vis == 0) && (dx.m == 2) && (dx.d > 28)) || ((vis == 1) && (dx.m == 2) && (dx.d > 29)))
	{
		i = ERR_INCDATE;
		printf("Your date is incorrect. Impossible February date. Your date is %d/%d/%d. Error code is %d\n", dx.d, dx.m, dx.y, i);
		return i;
	}
	i = CORRECT_DATE;
	if (dx.y > 1)
	{
		int e = dx.y - 1;
		{
			*number = dx.d + days_before_month[dx.m] + (is_leap(dx.y) && dx.m > 2) + e * 365 + e / 4 - e / 100 + e / 400;
			return i;
		}
	}
	else
	{
		*number = dx.d + days_before_month[dx.m] + dx.y * 365;
		return i;
	}
}
int second_step(char *date1, char *date2)
{
	int res, pr1, pr2, result1, result2;
	pr1 = ymd_to_days(date1, &result1);
	pr2 = ymd_to_days(date2, &result2);
	if ((pr1 == 0) && (pr2 == 0))
	{
		res = abs(result1 - result2) + 1;
		return res;
	}
	else return -1;
}