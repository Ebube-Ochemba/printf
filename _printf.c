#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string.
 *
 * Return: The number of characters printed.
*/

int _printf(const char *format, ...)
{
	va_list args; /* initialize type for iterating arguments */
	int j, i = 0, numbyte = 0;

	/* stuct to group specifiers */
	selcfunc spec[] = {
		{'%', print_percent},
		{'c', print_char},
		{'s', print_str}};

	va_start(args, format);

	while (format && format[i]) /*iterate format */
	{
		if (format[i] != '%') /* print chars that are not % only */
			numbyte += write(1, &format[i], 1);

		else
		{
			i++; /* move pointer past % */
			j = 0;

			while (j < 2) /* iterate specifiers */
			{
				if (format[i] == spec[j].c)
				{
					numbyte += spec[j].f(args);
					break; /* exit loop */
				}
				j++;
			}
		}
		i++;
	}
	va_end(args);
	return (numbyte);
}
