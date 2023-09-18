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

/**
 * det_hex_up - determines the character corresponding to hexadecimal
 * @n: number
 * Return: character
*/
char det_hex_up(int n)
{
	char c;

	if (n < 10)
		c = n + '0';
	else if (n == 10)
		c = 'A';
	else if (n == 11)
		c = 'B';
	else if (n == 12)
		c = 'C';
	else if (n == 13)
		c = 'D';
	else if (n == 14)
		c = 'E';
	else if (n == 15)
		c = 'F';
	return (c);
}

/**
 * print_hex_up - turns an integer to hexadecimal
 * @args: a variable argument list
 * Return: number of printed characters
*/
int print_hex_up(va_list args)
{
	unsigned int num, n;
	int size = 0, counter;
	char *c;

	num = va_arg(args, int);
	if (num < 16)
	{
		*c = det_hex_up(num);
		return (write(1, &c, 1));
	}
	n = num;
	while (n != 0)
	{
		size++;
		n = n / 16;
	}
	c = (char *) malloc(size + 1);
	if (!c)
		return (-1);
	for (counter = size - 1; counter >= 0; counter--)
	{
		c[counter] = det_hex_up(num % 16);
		num = num / 16;
	}
	c[size] = '\0';
	write(1, c, size);
	free(c);
	return (size);
}
