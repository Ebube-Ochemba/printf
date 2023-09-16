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
	int spec_found, j, i = 0, numbyte = 0;
	selcfunc spec[] = {
		{'%', print_percent}, {'c', print_char}, {'s', print_str}};

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format && format[i]) /*iterate format */
	{
		if (format[i] != '%') /* print chars that are not % only */
		{
			if (write(1, &format[i], 1))
				numbyte += 1;
		}
		else /* iterate format */
		{
			i++; /* move pointer past % */
			j = 0;
			spec_found = 0; /* flag to indicate specifier */
			while (j < 3) /* iterate specifiers */
			{
				if (format[i] == spec[j].c) /* specifier match */
				{
					numbyte += spec[j].f(args);
					spec_found = 1; /* update flag */
					break; /* exit loop */
				}
				j++;
			}
			if (!spec_found) /* unknown specifier */
			{
				numbyte += unknown(format[i]);
			}
		}
		i++;
	}
	va_end(args);
	return (numbyte); /* number of char printed */
}
