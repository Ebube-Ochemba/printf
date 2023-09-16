#include "main.h"

/**
 * calclen - Calculates the lenght of a string.
 * @s: A pointer to the string.
 *
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

	write(1, &c, 1);
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
		str = "";
	}

	len = calclen(str);
	write(1, str, len);
	return (len);
}
