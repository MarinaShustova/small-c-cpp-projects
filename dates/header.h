#ifndef PROG_1 
#define PROG_1 
#include <stdio.h> 
#include <ctype.h> 
#define CORRECT_DATE 0
#define ERR_NOSTR 1 
#define ERR_INCD 2 
#define ERR_INCM 3
#define ERR_INCY 4
#define ERR_NODIG 5 
#define ERR_INCDATE 6
int ymd_to_days(char *str, int *number);
int second_step(char *date1, char *date2);
struct dates {
	unsigned int y;
	unsigned char m;
	unsigned char d;
};
#endif