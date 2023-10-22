#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
} node;

int main(void)
{
	node *head = NULL;
	node *temp = NULL;

	head = malloc(sizeof(node));

	head->data = 12;
	head->link = NULL;

	temp = malloc(sizeof(node));
	temp->data = 24;
	temp->link = NULL;
	head->link = temp;



	printf("%d\n%d\n", head->data, head->link->data);

	return (0);
}
