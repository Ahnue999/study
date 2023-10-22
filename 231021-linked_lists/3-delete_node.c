#include "lists.h"

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
