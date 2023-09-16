#include "main.h"

/**
 * calclen - Calculates the lenght of a string.
 * @s: A pointer to the string.
 * Return: Length of the string.
 */
int calclen(char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * print_char - prints char.
 * @args: specifier.
 * Return: Number of printed char.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	if (write(1, &c, 1) == -1)
		return (0);
	return (1);
}

/**
 * print_str - prints a string.
 * @args: specifier.
 * Return: Number of printed char (string length).
 */
int print_str(va_list args)
{
	char *str;
	int len;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
		return (write(1, str, 6));
	}

	len = calclen(str);
	if (write(1, str, len) == -1)
		return (0);
	return (len);
}

/**
 * print_percent - prints %
 * @args: specifiers
 * Return: number of printed characters
*/
int print_percent(va_list args)
{
	char c = va_arg(args, int);

	c = '%';
	if (write(1, &c, 1) == -1)
		return (0);
	return (1);
}

/**
 * unknown - prints % and unknown characters
 * @c: pointer to unknown character
 * Return: number of printed characters
*/
int unknown(char c)
{
	if (write(1, "%", 1) == -1)
		return (0);
	if (write(1, &c, 1) == -1)
		return (0);
	return (2);
}
