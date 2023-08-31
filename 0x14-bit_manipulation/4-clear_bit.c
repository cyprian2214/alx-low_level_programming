#include "main.h"

/**
 * clear_bit - Clears the value of a bit to 0 at a given index.
 * @n: Pointer to the number to modify.
 * @index: The index of the bit to clear.
 * Return: 1 if successful, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8) /* Check if index is valid */
		return (-1);

	*n = (*n) & ~(1UL << index); /* Use bitwise AND with negation to clear the bit at index */

	return (1);
}
