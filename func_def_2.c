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
		{'s', print_str}
	};

	int j, numbyte = 0;
	int spec_found = 0; /* flag to indicate specifier */

	for (j = 0; j < 3; j++) /* iterate specifiers */
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
