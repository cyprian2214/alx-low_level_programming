#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * create_file - Create a file and write text content to it.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content) {
    int fd, write_result;
    mode_t mode = S_IRUSR | S_IWUSR; /* Permissions: rw------- */

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);

    if (fd == -1)
        return (-1);

    if (text_content != NULL) {
        write_result = write(fd, text_content, strlen(text_content));
        if (write_result == -1) {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
