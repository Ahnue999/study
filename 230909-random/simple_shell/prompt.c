#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point.
 * Return: always 0.
 */
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;

	printf("$ ");
	fflush(stdout);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}
