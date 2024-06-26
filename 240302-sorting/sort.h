#ifndef _SORT_H_
#define _SORT_H_

#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

int swap(int *, int *);
void selection_sort(int arr[], int);
void print_array(const int *array, size_t size);

#endif
