#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string containing binary digits.
 * Return: Converted number, or 0 if invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i = 0;

	if (!b)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] == '0' || b[i] == '1')
		{
			result = result << 1; /* Shift result to the left */
			result += b[i] - '0'; /* Convert char to int and add to result */
		}
		else
			return (0); /* Invalid input, return 0 */
		i++;
	}

	return (result);
}
