#include <stdio.h>

int main(__attribute__((unused)) int ac, char **argv)
{
	while (*argv)
	{
		printf("%s\n", *argv);
		argv++;
	}

	return (0);
}
