#include "main.h"

/**
 * print_unsigned_int - prints an unsigned int.
 * @args: A variable argument list.
 *
 * Return: Returns the number of bytes printed.
 */

int print_unsigned_int(va_list args)
{
	unsigned int n, temp;
	int counter, len = 0;
	char *c;

	n = va_arg(args, int); /* retrieve argument value and store */
	if (n == 0) /* special case */
		return (write(1, "0", 1));
	temp = n;
	while (temp != 0) /* calculate number of digits */
	{
		temp = temp / 10;
		len++;
	}
	c = (char *) malloc(len + 1);
	if (!c) /* malloc check */
		return (-1);

	/* iterate in reverse */
	for (counter = len - 1; counter >= 0; counter--)
	{
		c[counter] = (n % 10) + '0'; /* convert to a char & store */
		n = n / 10; /* update value */
	}
	c[len] = '\0';
	write(1, c, len);
	free(c); /* clear memory */
	return (len);
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
		c[counter] = det_hex_up(num % 16);
		num = num / 16;
	}
	c[size] = '\0';
	write(1, c, size);
	free(c);
	return (size);
}

/**
 * print_string - prints string and non printable chars in hexadecimal
 * @args: a variable argument list
 * Return: number of printed characters
*/
int print_string(va_list args)
{
	char *str;
	int len = 0, counter, char_to_int, temp;
	char c, c1, c2;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
		return (write(1, str, 6));
	}
	for (counter = 0; str[counter] != '\0'; counter++)
	{
		if (str[counter] >= 32 && str[counter] < 127)
		{
			write(1, &str[counter], 1);
			len++;
		} else
		{
			char_to_int = str[counter];
			write(1, "\\x", 2);
			len = len + 2;
			if (char_to_int < 16)
			{
				write(1, "0", 1);
				c = det_hex_up(char_to_int);
				write(1, &c, 1);
				len = len + 2;
			} else
			{
				temp = char_to_int % 16;
				c2 = det_hex_up(temp);
				char_to_int = char_to_int / 16;
				temp = char_to_int % 16;
				c1 = det_hex_up(temp);
				write(1, &c1, 1);
				write(1, &c2, 1);
				len = len + 2;
			}
		}
	}
	if (write(1, str, len) == -1)
		return (0);
	return (len);
}
