#include <stdio.h>
#include <stdarg.h>

void func(const char *s, ...)
{
	va_list ap;
	int i;

	va_start(ap, s);
	for (i = 0; i >= 0; i = va_arg(ap, int))
		printf("%d\n", i);
	va_end(ap);
}
int main()
{
	func("HI ", 3, 1, 5, 11, 4, 44);

	return (0);
}
