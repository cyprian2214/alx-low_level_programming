#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) in a listint_t linked list
 * @head: pointer to the first node in the list
 *
 * Return: sum of all the data, or 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
    int sum = 0;
    listint_t *current = head;

    while (current)
    {
        sum += current->n;
        current = current->next;
    }

    return sum;
}
