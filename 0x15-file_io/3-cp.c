#include "main.h"
#include <stdio.h>

/**
 * check_open_files - checks if files can be opened.
 * @source_fd: Source file descriptor.
 * @dest_fd: Destination file descriptor.
 * @argv: Arguments vector.
 *
 * Return: No return.
 */
void check_open_files(int source_fd, int dest_fd, char *argv[])
{
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Copies the content from one file to another.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd, err_close;
	ssize_t nchars, nwr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	source_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	check_open_files(source_fd, dest_fd, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(source_fd, buffer, 1024);
		if (nchars == -1)
			check_open_files(-1, 0, argv);
		nwr = write(dest_fd, buffer, nchars);
		if (nwr == -1)
			check_open_files(0, -1, argv);
	}

	err_close = close(source_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		exit(100);
	}

	err_close = close(dest_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}
	return (0);
}

