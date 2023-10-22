#include "lists.h"

/**
 * add_node_end - adds a node at the end of the list.
 * @head: the list pointer.
 * @data: the data to add.
 *
 * Return: No return.
 */
void add_node_end(node *head, int data)
{
	node *temp, *ptr;
	ptr = head;

	temp = malloc(sizeof(node));

	temp->data = data;
	temp->next = NULL;

	while (ptr->next)
		ptr = ptr->next;

	ptr->next = temp;
}

/**
 * add_node_end_o - the optimized version.
 * @ptr: the last node of the list.
 * @data: the data to add.
 *
 * @Return: a pointer to the newly created
 * list member which is the last now.
 */
node *add_node_end_o(node *ptr, int data)
{
	node *temp = NULL;

	temp = malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	ptr->next = temp;
	return (temp);
}

node *add_node_begin(node *head, int data)
{
	node *ptr;

	ptr = malloc(sizeof(node));
	ptr->data = data;
	ptr->next = head;
	head = ptr;

	return (head);
}

void add_node_begin_o(node **head, int data)
{
	node *ptr;

	ptr = malloc(sizeof(node));
	ptr->data = data;
	ptr->next = *head;
	*head = ptr;
}

void add_node_mid(node *head, int data, int pos)
{
	int i;
	node *ptr, *temp;

	temp = head;
	for (i = 0; i < pos - 2; i++)
		temp = temp->next;

	ptr = malloc(sizeof(node));
	ptr->data = data;
	ptr->next = NULL;

	ptr->next = temp->next;
	temp->next = ptr;
}
