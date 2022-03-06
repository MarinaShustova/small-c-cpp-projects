#include <stdio.h>
#include <string.h>
typedef struct list
{
	char *content;
	struct list *next;
}list;
int main()
{
	char str[256];
	int length;
	list *head = NULL, *current;
	while (1)
	{
		if (gets(str) == NULL)
		{
			printf("Error with reading a line\n");
			return -1;
		}
		else if (str[0] == '.')
			break;
		else
		{
			length = strlen(str);
			current = (struct list*)malloc(sizeof(struct list));
			if (head == NULL)
			{
				current->next = NULL;
				current->content = (char *)malloc(length+1);
				strcpy(current->content, str);
				head = current;
			}
			else
			{	
				current->next = head;
				current->content = (char *)malloc(length + 1);
				strcpy(current->content, str);
				head = current;
			}
		}
	}
	while (head)
	{
		printf("%s\n", head->content);
		head = head->next;
	}
	return 0;
}