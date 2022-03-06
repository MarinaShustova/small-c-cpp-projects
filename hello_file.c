#include <stdio.h>
void main()
{
	char s[] = "Hello ";
	char s2[] = "world";
	char d[13];
	int c;
	FILE *in;
	printf(s);
	printf("\n");
	sprintf(d, "%s%s\n", s, s2);
	printf(d);
	printf("%c\n", getc(stdin));
	in = fopen("q.txt", "wb");
	while ((c = getc(in)) != EOF)
			putchar(c);
}