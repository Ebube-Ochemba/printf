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
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary}
	};

	int j, numbyte = 0;
	int spec_found = 0; /* flag to indicate specifier */

	for (j = 0; j < 6; j++) /* iterate specifiers */
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

/**
 * print_binary - turns integers to binary
 * @args: a variable argument list
 * Return: number of printed characters
*/
int print_binary(va_list args)
{
	int num, size = 0, counter, n;
	char *c;

	num = va_arg(args, int);
	if (num == 0)
		return (write(1, "0", 1));
	if (num > 0)
	{
		n = num;
		while (n != 0)
		{
			size++;
			n = n / 2;
		}
		c = (char *) malloc(size + 1);
		if (!c)
			return (-1);
		for (counter = size - 1; counter >= 0; counter--)
		{
			c[counter] = (num % 2) + '0';
			num = num / 2;
		}
		c[size] = '\0';
	}
	write(1, c, size);
	free(c);
	return (size);
}
