#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Prints output according to a format.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (format && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int ch = va_arg(args, int);

				putchar(ch);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int len = 0;

				while (str[len] != '\0')
					len++;
				fputs(str, stdout);
				count += len;
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
