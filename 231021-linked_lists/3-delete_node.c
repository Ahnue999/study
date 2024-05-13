#include "lists.h"

/**
 * delete_first_node - deletes the first node
 * of a list.
 * @head: the head pointer.
 *
 * Return: the new head pointer.
 */
node *delete_first_node(node *head)
{
	node *temp;

	if (!head)
	{
		printf("Already empty");
		return (head);
	}

	temp = head;
	head = head->next;
	
	free(temp);
	temp = NULL;
	return (head);
}

/**
 * delete_last_node - deletes the last node
 * of a list
 * @head: the head pointer.
 * Return: the new head pointer.
 */
node *delete_last_node(node *head)
{
	node *temp, *temp2;

	if (!head)
	{
		printf("Already empty");
		return (head);
	}
	else if (!head->next)
	{
		free(head);
		head = NULL;
		return (head);
	}
	else
	{
		temp = temp2 = head;
		while (temp->next != NULL)
		{
			temp2 = temp;
			temp = temp->next;
		}

		temp2->next = NULL;
		free(temp);
		temp = NULL;
	}

	return (head);
}

/**
 * delete_last_node_o - deletes the last node
 * of a list without needing to update the head.
 * @head: the head pointer of the list.
 *
 * Return: no return.
 */
void delete_last_node_o(node *head)
{
	node *temp;

	if (!head)
	{
		printf("Already empty");
		return;
	}
	else if (!head->next)
	{
		free(head);
		head = NULL;
		return;
	}
	else
	{
		temp = head;
		while (temp->next->next)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}

/**
 * del_pos_o - delete a node at a certain position.
 * @head: the head pointer.
 * @pos: the position of the node to be deleted.
 *
 * Return: NO return.
 */
void del_pos_o(node **head, int pos)
{
	node *previous, *current;
	
	previous = current = *head;

	if (*head == NULL)
		printf("The list is empty!!!\n");
	else if (pos == 1)
	{
		*head = current->next;
		free(current);
		current = previous = NULL;
	}
	else
	{
		while(pos >= 2)
		{
			previous = current;
			if (current->next)
				current = current->next;
			else
			{
				printf("Invalid position\n");
				return;
			}
			pos--;
		}
		previous->next = current->next;
		free(current);
		current = previous = NULL;
	}
}

/**
 * del_list - deletes the whole list.
 * @head: the list pointer by refrence.
 *
 * Return: nothing.
 */
void del_list(node **head)
{
	node *temp = *head;

	while (temp)
	{
		temp = temp->next;
		free(*head);
		*head = temp;
	}
}
