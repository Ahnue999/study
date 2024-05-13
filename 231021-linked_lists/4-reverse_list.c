#include "lists.h"

/*
 * rev_list - reverse a linked list.
 * @head: the list pointer.
 *
 * Return: the new head pointer.
 */
node *rev_list(node *head)
{
	node *before, *after;

	before = after = NULL;

	while (head)
	{
		after = head->next;
		head->next = before;
		before = head;
		head = after;
	}
	head = before;

	/* To release *before as *next == NULL*/
	before = after;

	return (head);
}
