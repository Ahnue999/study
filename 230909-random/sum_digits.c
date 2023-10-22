#include <stdio.h>

int sum_digits(int n)
{
	if (n == 0)
		return (0);
	else 
		return (n % 10) + sum_digits(n / 10);
}

int main(void)
{
	int n = 911;

	printf("%d\n", sum_digits(n));

	return (0);
}
