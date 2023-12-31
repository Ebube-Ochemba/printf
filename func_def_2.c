#include "main.h"


/**
 * print_int - prints an int.
 * @args: A variable argument list.
 *
 * Return: Returns the number of bytes printed.
 */

int print_int(va_list args)
{
	int n, numchar =  0, temp, counter, len = 0;
	char *c;

	n = va_arg(args, int); /* retrieve argument value and store */
	if (n == 0) /* special case */
	{
		write(1, "0", 1);
		numchar++;
	}
	else if (n < 0)
	{
		write(1, "-", 1); /* indicate negative value */
		if (n == -2147483648) /* special case */
		{
			write(1, "2147483648", 10);
			return (11);
		}
		n = n * -1; /* update absolute value */
		numchar++;
		len = numchar - 1; /* b/c of the negative sign */
	}
	temp = n;
	while (temp != 0) /* calculate number of digits */
	{
		temp = temp / 10;
		numchar++;
		len++;
	}
	c = (char *) malloc(len + 1);
	if (!c) /* malloc check */
		return (-1);
	for (counter = len - 1; counter >= 0; counter--) /* iterate in reverse */
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
 * print_binary - turns integers to binary
 * @args: a variable argument list
 * Return: number of printed characters
*/

int print_binary(va_list args)
{
	unsigned int num, n;
	int size = 0, counter;
	char *c;

	num = va_arg(args, int); /* retrieve argument value and store */
	if (num == 0) /* special case */
		return (write(1, "0", 1));
	if (num > 0) /* positive integers */
	{
		n = num;
		while (n != 0) /* count number of binary digits */
		{
			size++;
			n = n / 2;
		}
		c = (char *) malloc(size + 1);
		if (!c) /* malloc check */
			return (-1);
		for (counter = size - 1; counter >= 0; counter--)
		{
			c[counter] = (num % 2) + '0';
			num = num / 2; /* update value */
		}
		c[size] = '\0'; /* add NULL byte */
	}
	write(1, c, size); /* print binary number */
	free(c); /* clear memory */
	return (size);
}

/**
 * print_oct - turns an integer to octal
 * @args: a variable argument list
 * Return: number of printed characters
*/
int print_oct(va_list args)
{
	unsigned int num, n;
	int allocsize = 0, counter;
	char *c;
	char c2;

	num = va_arg(args, int);
	if (!num)
		return (write(1, "0", 1));
	if (num < 8)
	{
		c2 = num + '0';
		return (write(1, &c2, 1));
	}
	if (num > 0)
	{
		n = num;
		while (n != 0)
		{
			allocsize++;
			n = n / 8;
		}
		c = (char *) malloc(allocsize + 1);
		if (!c)
			return (-1);
		for (counter = allocsize - 1; counter >= 0; counter--)
		{
			c[counter] = (num % 8) + '0';
			num = num / 8;
		}
		c[allocsize] = '\0';
	}
	write(1, c, allocsize);
	free(c);
	return (allocsize);
}

/**
 * det_hex_low - determines the character corresponding to hexadecimal
 * @n: number
 * Return: character
*/
char det_hex_low(int n)
{
	char c;

	if (n < 10)
		c = n + '0';
	else if (n == 10)
		c = 'a';
	else if (n == 11)
		c = 'b';
	else if (n == 12)
		c = 'c';
	else if (n == 13)
		c = 'd';
	else if (n == 14)
		c = 'e';
	else if (n == 15)
		c = 'f';
	return (c);
}

/**
 * print_hex_low - turns an integer to hexadecimal
 * @args: a variable argument list
 * Return: number of printed characters
*/
int print_hex_low(va_list args)
{
	unsigned int num, n;
	int size = 0, counter;
	char *c;

	num = va_arg(args, int);
	if (num == 0)
	{
		return (write(1, "0", 1));
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
		c[counter] = det_hex_low(num % 16);
		num = num / 16;
	}
	c[size] = '\0';
	write(1, c, size);
	free(c);
	return (size);
}
