#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * node - a node structure.
 * @data: the data part of the node.
 * @next: the pointer to the next element.
 *
 * Discription: Just an integer node struct.
 */
typedef struct node {
	int data;
	struct node *next;
} node;

void print_list(node *);
int count_nodes(node *);
void add_node_end(node *, int);
void add_node_begin_o(node **, int);
node *add_node_begin(node *, int);
node *add_node_end_o(node *, int);
void add_node_mid(node *, int, int);
node *delete_first_node(node *);
node *delete_last_node(node *);
void delete_last_node_o(node *);
void del_pos(node *, int);
void del_pos_o(node **, int);
void del_list(node **);

#endif
