#include "bits.h"

/**
 * count_true - counts the 1 bits of an int.
 * @n: the integer.
 *
 * Return: the count of 1.
 */
int count_true(unsigned int n)
{
	int count;

	for (count = 0; n != 0; n >>= 1)
	{
		if (n & 01)
			count++;
	}

	return (count);
}
