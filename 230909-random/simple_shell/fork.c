#include <stdio.h>
#include <unistd.h>

/**
 * main - entry point.
 *
 * Return: 0 when succes and 1 otherwise.
 */
int main(void)
{
	pid_t my_pid;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (1);
	}

	my_pid = getpid();
	printf("My pid is %d\n", my_pid);

	return (0);
}
