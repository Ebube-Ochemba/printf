#include "main.h"

/**
 * print_unsigned_int - prints an unsigned int.
 * @args: A variable argument list.
 *
 * Return: Returns the number of bytes printed.
 */

int print_unsigned_int(va_list args)
{
	unsigned int n, numchar =  0, temp, counter, len = 0;
	char *c;

	n = va_arg(args, int); /* retrieve argument value and store */
	if (n == 0) /* special case */
	{
		write(1, "0", 1);
		numchar++;
	}
	else
	{
		temp = n;
		while (temp != 0) /* calculate number of digits */
		{
			temp = temp / 10;
			numchar++;
			len++;
		}
	}
	c = (char *) malloc(len + 1);
	if (!c) /* malloc check */
		return (-1);

	/* iterate in reverse */
	for (counter = len - 1; counter != (unsigned int)-1; counter--)
	{
		c[counter] = (n % 10) + '0'; /* convert to a char & store */
		n = n / 10; /* update value */
	}
	if ((write(1, c, len) == -1)) /* print c */
		return (0);
	free(c); /* clear memory */
	return (numchar);
}
