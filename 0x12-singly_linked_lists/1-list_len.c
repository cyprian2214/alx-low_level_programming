#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Counts the number of elements in a linked list.
 * @h: Pointer to the list_t list.
 *
 * Return: Number of elements in the linked list.
 */
size_t list_len(const list_t *h)
{
    size_t elements_count = 0;

    while (h)
    {
        elements_count++;
        h = h->next;
    }

    return (elements_count);
}
