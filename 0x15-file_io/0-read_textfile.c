#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: the filename.
 * @letters: the number of letters to print.
 *
 * Return: the number of letters printed. If it fails, it returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_write;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	n_read = read(fd, buf, letters);
	n_write = write(STDOUT_FILENO, buf, n_read);

	close(fd);

	free(buf);

	return (n_write);
}

