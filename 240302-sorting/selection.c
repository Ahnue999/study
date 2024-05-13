#include "sort.h"

/**
 * selection_sort - selection sort on an array.
 */
void selection_sort(int arr[], int size)
{
		int i, j,  min_idx;
		if (size < 2)
				return;

		for (i = 0; i < size - 1; i++)
		{
				min_idx = i;
				for (j = i + 1; j < size; j++)
				{
						if (arr[j] < arr[min_idx])
								min_idx = j;
				}
				if (min_idx != i)
						swap(&arr[i], &arr[min_idx]);
		}
}
