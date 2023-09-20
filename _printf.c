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
	int i = 0, numbyte = 0;

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
		else /* handle specifier */
		{
			if (format[i + 1] == '%')
				numbyte += print_percent();
			else
				numbyte += sel_spec(format[i + 1], args);
			i++; /* skip the specifier */
		}
		i++; /* move to next char in format string */
	}
	va_end(args);
	return (numbyte); /* number of char printed */
}
