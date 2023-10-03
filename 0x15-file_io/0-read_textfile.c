#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a text file and print its content to STDOUT.
 * @filename: The name of the text file to read.
 * @letters: The number of letters (bytes) to read and print.
 *
 * Return: On success, the number of bytes read and printed (w).
 *         On failure or if filename is NULL, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buf;
    ssize_t fd, w, t;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buf = malloc(sizeof(char) * letters);
    t = read(fd, buf, letters);
    w = write(STDOUT_FILENO, buf, t);

    free(buf);
    close(fd);

    return (w);
}
