#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;
/**
 * main - entry point.
 *
 * Return: always succes (0);
 */
int main(int argc, char **argv)
{
	char *args[3];

	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "Error: Usage %s/\"func\"\n", argv[0]);
		exit(99);
	}

	args = {"/bin/", argv[1], NULL}
	execve(args[0], args, environ);
	perror("execve failed");
	exit(98);
}
