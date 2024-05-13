#include "bits.h"

int main(void)
{
	int n;

	n = 24;

	printf("There are %d [1] bits in %d\n", count_true(n), n);

	return (0);
}
