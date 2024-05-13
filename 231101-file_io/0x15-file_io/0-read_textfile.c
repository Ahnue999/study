#include "main.h"

/**
 * read_textfile - reads a text file then prints it
 * to the POSIX standard output.
 * @filename: the name of the file to read from.
 * @letters: the number of letters to read and print.
 *
 * Return: The number of bytes it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int read_amount, write_amount;
	char *buffer;


	if (!filename)
		return (0);

	buffer = malloc(sizeof(char) * letters + 1);
	if (!buffer)
		return (0);

	open(filename, O_RDONLY);

	read_amount = read(3, buffer, letters);
	write_amount = write(1, buffer, letters);

	if (write_amount == -1)
		return (0);

	return (read_amount);
}
