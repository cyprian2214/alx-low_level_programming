#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip to get from n to m.
 * @n: First number.
 * @m: Second number.
 * Return: Number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result > 0)
	{
		count += xor_result & 1; /* Count the least significant bit */
		xor_result >>= 1; /* Right shift to process the next bit */
	}

	return (count);
}
