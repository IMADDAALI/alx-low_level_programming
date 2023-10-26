#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result;
	int length, weight;

	if (!b)
		return (0);

	result = 0;

	for (length = 0; b[length] != '\0'; length++)
		;

	for (length--, weight = 1; length >= 0; length--, weight *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}

		if (b[length] & 1)
		{
			result += weight;
		}
	}

	return (result);
}

