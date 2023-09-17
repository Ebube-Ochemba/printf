#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct sf - A struct for organizing functions based on specifiers.
 * @c: Specifier char.
 * @f: Function pointer to print in correct format.
 */

typedef struct sf
{
	char c;
	int (*f)(va_list);
} selcfunc;

int _printf(const char *format, ...);
int calclen(char *s);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int unknown(char c);
int sel_spec(char specifier, va_list args);
int print_int(va_list args);
int print_binary(va_list args);

#endif
