#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - Print an error message and exit with a specified exit code.
 * @code: The exit code.
 * @format: The format string for the error message.
 */
void error_exit(int code, const char *format, ...) {
    va_list args;
    va_start(args, format);
    dprintf(STDERR_FILENO, format, args);
    va_end(args);
    exit(code);
}

int main(int argc, char *argv[]) {
    int fd_from, fd_to, read_count, write_count;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to\n");

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        error_exit(99, "Error: Can't write to %s\n", argv[2]);

    while ((read_count = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_count = write(fd_to, buffer, read_count);
        if (write_count == -1)
            error_exit(99, "Error: Can't write to %s\n", argv[2]);
    }

    if (read_count == -1)
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);

    if (close(fd_from) == -1)
        error_exit(100, "Error: Can't close fd %d\n", fd_from);

    if (close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd %d\n", fd_to);

    return 0;
}
