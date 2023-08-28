#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
    size_t num = 0;

    for (; h; h = h->next)
    {
        printf("%d\n", h->n);
        num++;
    }

    return num;
}
