#include <stdio.h>
#include "sort.h"

/**
 * main - main function
 *
 * Return: 1 or 0
 */
int main(void)
{
		int a[] = {3, 1, 2, 6, 3, 4};

		selection_sort(a, 6);
		print_array(a, 6);

		return (0);
}
