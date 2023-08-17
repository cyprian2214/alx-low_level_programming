#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * This function prints a variable number of arguments based on the provided format string.
 * It supports printing characters, integers, floats, and strings.
 *
 * @param format A string specifying the format of the arguments to be printed.
 *               Supported format specifiers: 'c' for character, 'i' for integer,
 *               'f' for float, 's' for string.
 * @param ...    The list of arguments corresponding to the format specifiers.
 *               The number and type of arguments should match the format string.
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *sep = "";

	va_list list;

	va_start(list, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sep, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", sep, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", sep, va_arg(list, double));
					break;
				case 's':
					str = va_arg(list, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", sep, str);
					break;
				default:
					i++;
					continue;
			}
			sep = ", ";
			i++;
		}
	}

	printf("\n");
	va_end(list);
}
