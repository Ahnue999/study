#include "variadic_functions.h"

/**
  * print_numbers - sum all its arguments.
  * @n: the first argument.
  *
  * Return : the sum.
  */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;

	va_start(ap, separator);
	for (i = 0; i < n; i++)
	{
		if (i < n - 1)
			printf("%d%s", va_arg(ap, int), separator);
		else
			printf("%d\n", va_arg(ap, int));
	}
}
