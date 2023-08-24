#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all the elements of a linked list.
 * @h: Pointer to the list_t list to be printed.
 * 
 * This function iterates through the linked list pointed to by 'h'
 * and prints information about each node's string content and length.
 * If a node's string is NULL, it prints "(nil)" for the content.
 * The format for each printed node is "[length] content".
 * 
 * @return The number of nodes printed.
 */
size_t print_list(const list_t *h)
{
    size_t nodes_printed = 0;

    while (h)
    {
        if (!h->str)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", h->len, h->str);
        
        h = h->next;
        nodes_printed++;
    }

    return nodes_printed;
}
