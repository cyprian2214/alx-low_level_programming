#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL-terminated string to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd, write_result, len = 0;

    if (filename == NULL)
        return (-1);

    if (text_content == NULL)
        return (1);

    while (text_content[len])
        len++;

    fd = open(filename, O_WRONLY | O_APPEND);

    if (fd == -1)
        return (-1);

    write_result = write(fd, text_content, len);

    if (write_result == -1)
    {
        close(fd);
        return (-1);
    }

    close(fd);
    return (1);
}
