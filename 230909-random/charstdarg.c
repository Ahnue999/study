#include <stdio.h>
#include <stdarg.h>

void func(const char *s, ...)
{
	va_list ap;
	int i;

	va_start(ap, s);
	for (i = 0; i >= 0; i = va_arg(ap, int))
		printf("%c\n", (char)i);
	va_end(ap);
}
int main()
{
	func("HI ", 'h', 'e', 'l', 'l', 'o', -1);

	return (0);
}
