#include "lists.h"

int main(void)

{
	node *head;
	node *current;

	head = malloc(sizeof(node));

	head->data = 0;
	head->next = NULL;

	/*
	current = malloc(sizeof(node));
	current->data = 1;
	current->next = NULL;

	head->next = current;

	current = malloc(sizeof(node));
	current->data = 2;
	current->next = NULL;

	head->next->next = current;
	*/

	/*Optimized add node*/
	current = head;
	current = add_node_end_o(current, 1);
	current = add_node_end_o(current, 3);

	current = head;

	add_node_mid(head, 2, 3);

	head = delete_first_node(head);
	del_list(&head);

	printf("There are %d nodes in this list\n", count_nodes(head));
	printf("\n__________THE_LIST__________\n\n"); 
	print_list(head);
	printf("\n__________THE_END___________\n"); 

	/*
	add_node_end(head, 3);
	printf("\\\\After adding one node to the end\\\\\n");
	printf("There are %d nodes in this list\n", count_nodes(head));
	printf("_________THE LIST_________\n\n"); 
	print_list(head);
	printf("_________THE END_________\n"); 
	*/

	return(0);
}
