#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    if (*head == NULL || index < 0)
        return -1;

    listint_t *current = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        free(current);
        return 1;
    }

    for (unsigned int i = 0; current != NULL && i < index - 1; ++i)
        current = current->next;

    if (current == NULL || current->next == NULL)
        return -1;

    listint_t *temp = current->next;
    current->next = temp->next;
    free(temp);

    return 1;
}
