#include "main.h"

int print_int(int n)
{
	int m, d;
	int count, length;

	length = 0;
	if (n < 0)
	{
		_putchar('-');
		m = n * -1;
		length++;
	}
	else
	{
		m = n;
	}

	d = m;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (; count >= 1; count /= 10, length++)
		_putchar('0' + ((m / count) % 10));

	return (length);
}
