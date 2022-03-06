#include "header.h"
int lex(char *str, int out)
{
	FILE *fp = 0;
	int i = 0, j;
	if (!str || !*str)
	{
		printf("Error. Empty string");
		j = ERR_NOSTR;
		return j;
	}
	if (out == 1)
		fp = fopen("result.txt", "w");
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		if ((isalpha(str[i]) != 0) || (str[i]) == '_')
		{
			if (out == 2)
			{
				printf("%d ID \"%c", i, str[i]);
				i++;
				while ((str[i] != ' ') && (str[i] != '\0'))
				{
					if ((ispunct(str[i]) != 0) && (str[i] != '_'))
						break;
					printf("%c", str[i]);
					i++;
				}
				printf("\"\n");
			}
			if (out == 1)
			{
				fprintf(fp, "%d ID \"%c", i, str[i]);
				i++;
				while ((str[i] != ' ') && (str[i] != '\0'))
				{
					if ((ispunct(str[i]) != 0) && (str[i] != '_'))
						break;
					fprintf(fp,"%c", str[i]);
					i++;
				}
				fprintf(fp, "\"\n");
			}
		}
		if (isdigit(str[i]) != 0)
		{
			if (out == 2)
			{
				printf("%d INT \"%d", i, (str[i] - '0'));
				i++;
				while (isdigit(str[i]) != 0)
				{
					printf("%d", str[i] - '0');
					i++;
				}
				printf("\"\n");
			}
			if (out == 1)
			{
				fprintf(fp, "%d INT \"%d", i, (str[i] - '0'));
				i++;
				while (isdigit(str[i]) != 0)
				{
					fprintf(fp, "%d", str[i] - '0');
					i++;
				}
				fprintf(fp, "\"\n");
			}
		}
		if (ispunct(str[i]) != 0)
		{
			if (out == 2)
			{
					printf("%d SYM \"%c\"\n", i, str[i]);
					i++;
			}
			if (out == 1)
			{
					fprintf(fp, "%d SYM \"%c\"\n", i, str[i]);
					i++;
			}
		}
	}
	if (out == 1)
		fclose(fp);
	j = NO_ERR;
	return j;
}