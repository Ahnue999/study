#include "lists.h"

int count_nodes(node *head)
{
	int i = 0;
	node *ptr = NULL;

	if (head == NULL)
		return (0);

	ptr = head;

	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}

	return (i);
}
void print_list(node *head)
{
	node *ptr = NULL;

	if (head == NULL)
	{
		printf("list is empty\n");
		return;
	}

	ptr = head;

	while (ptr)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}
