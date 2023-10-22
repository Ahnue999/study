#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void)
{
	int i;

	int arr[] = {5, 2, 7, 3, 1};
	qsort(arr, 5, sizeof(arr[0]), compare);

	for (i = 0; i < 5; i++)
		printf("%d\n", arr[i]);
}

int compare(const void *a, const void *b)
{
	int x = *((int *)a);
	int y = *((int *)b);

	return (x - y);
}
