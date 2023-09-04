#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char *create_buffer(void);
void close_file(int fd);
int copy_file(const char *file_from, const char *file_to);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
    char *buffer;

    buffer = malloc(sizeof(char) * BUFFER_SIZE);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't allocate memory\n");
        exit(99);
    }

    return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
    int c;

    c = close(fd);

    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

/**
 * copy_file - Copies the contents of one file to another file.
 * @file_from: The source file to copy from.
 * @file_to: The destination file to copy to.
 *
 * Return: 0 on success.
 */
int copy_file(const char *file_from, const char *file_to)
{
    int from, to, r, w;
    char *buffer;

    buffer = create_buffer();
    from = open(file_from, O_RDONLY);
    to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);

    if (from == -1 || to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't %s %s\n", from == -1 ? "read from" : "write to", from == -1 ? file_from : file_to);
        free(buffer);
        exit(98);
    }

    do {
        r = read(from, buffer, BUFFER_SIZE);
        if (r == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Can't read from file %s\n", file_from);
            free(buffer);
            exit(98);
        }

        w = write(to, buffer, r);
        if (w == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Can't write to %s\n", file_to);
            free(buffer);
            exit(99);
        }

    } while (r > 0);

    free(buffer);
    close_file(from);
    close_file(to);

    return (0);
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    return (copy_file(argv[1], argv[2]));
}
