#include "main.h"

/**
 * sel_spec - Select a function based on specifier matched.
 * @specifier: The specifier to use.
 * @args: A variable argument list.
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

int print_int(va_list args)
{
	int n, numchar =  0, temp, counter, m = 0;
	char *c;

	n = va_arg(args, int);
	if (n == 0)
	{
		write(1, "0", 1);
		numchar++;
		return (1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		numchar++;
		m = numchar - 1;
	}
	temp = n;
	while (temp != 0)
	{
		temp = temp / 10;
		numchar++;
		m++;
	}
	c = (char *) malloc (m + 1);
	if (!c)
		return (-1);
	for (counter = m - 1; counter >= 0; counter--)
	{
		c[counter] = (n % 10) + '0'; /*to convert it to a char*/
		n = n / 10;
	}
	write (1, c, m);
	free(c);
	return (numchar);
}
