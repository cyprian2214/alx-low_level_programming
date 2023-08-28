#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return: resulting sum
 */
int sum_listint(listint_t *head)
{
    int sum = 0;

    for (listint_t *temp = head; temp; temp = temp->next)
    {
        sum += temp->n;
    }

    return sum;
}
