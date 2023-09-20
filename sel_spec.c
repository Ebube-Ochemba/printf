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
		{'c', print_char},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'o', print_oct},
		{'u', print_unsigned_int},
		{'x', print_hex_low},
		{'X', print_hex_up},
		{'S', print_string},
		{'p', print_address}
	};

	int j, numbyte = 0;
	int spec_found = 0; /* flag to indicate specifier */

	for (j = 0; j < 11; j++) /* iterate specifiers */
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
