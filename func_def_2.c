#include "main.h"

/**
 * sel_spec - Select a function based on specifier matched.
 * @specifier: The specifier to use.
 * @args: A variable BOBargument list.
 *
 * Return: number of bytes printed.
 */

int sel_spec(char specifier, va_list args)
{
	selcfunc spec[] = {
		{'%', print_percent},
		{'c', print_char},
		{'s', print_str},
		{'d', print_int}
	};

	int j, numbyte = 0;
	int spec_found = 0; /* flag to indicate specifier */

	for (j = 0; j < 4; j++) /* iterate specifiers */
	{
		if (specifier == spec[j].c) /* specifier match */
		{
			numbyte += spec[j].f(args);
			spec_found = 1; /* update flag */
			break; /* exit loop */
		}
	}
	if (!spec_found) /* unknown specifier */
	{
		numbyte += unknown(specifier);
	}
	return (numbyte);
}

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

	n = va_arg(args, int);
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (0);
		numchar++;
		return (1);
	}
	else if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (0);
		n = n * -1;
		numchar++;
		len = numchar - 1;
	}
	temp = n;
	while (temp != 0)
	{
		temp = temp / 10;
		numchar++;
		len++;
	}
	c = (char *) malloc(len + 1);
	if (!c)
		return (-1);
	for (counter = len - 1; counter >= 0; counter--)
	{
		c[counter] = (n % 10) + '0'; /* to convert it to a char */
		n = n / 10;
	}

	if ((write(1, c, len) == -1))
		return (0);
	free(c);

	return (numchar);
}