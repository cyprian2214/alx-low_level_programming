#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    int fd, read_count, write_count;
    char *buffer;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        free(buffer);
        return (0);
    }

    read_count = read(fd, buffer, letters);
    if (read_count == -1) {
        free(buffer);
        close(fd);
        return (0);
    }

    close(fd);

    write_count = write(STDOUT_FILENO, buffer, read_count);
    if (write_count == -1 || write_count != read_count) {
        free(buffer);
        return (0);
    }

    free(buffer);
    return (write_count);
}
