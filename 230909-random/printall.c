#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_all(const char * const format, ...)
{
	int i, j, c = 0;
	va_list ap;
	char * str;
	const char form[] = {"cifs"};


	i = 0;
	va_start(ap, format);
	while (format && format[i]);
	{
		j = 0;
		while (form[j])
		{
			if (format[i] == form[j] && c)
			{
				printf(", ");
				break;
			}j++;
		}
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(ap, int)), c = 1;
				break;
			case 'i':
				printf("%i", va_arg(ap, int)), c = 1;
				break;
			case 'f':
				printf("%f", va_arg(ap, double)), c = 1;
				break;
			case 's':
				str =  va_arg(ap, char *), c = 1;
				if (!str)
				{
					printf("(nil");
					break;
				}
				printf("%s", str);
				break;
		}i++;
	}
	printf("\n"), va_end(ap);
}
