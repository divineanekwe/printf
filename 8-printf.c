#include "main.h"

/**
  * _printf - prints to stdout using format specifications
  * @format: Character string
  *
  * Descriptoin - the character string @format can contain
  * strings to print and/or format specifications
  *
  * Return: The number of character(s) printed, including
  * the null terminating character '\0'
  */
int _printf(const char *format, ...)
{
	register int count = 0;
	va_list arg;
	const char *str;
	flags_t flags = {0, 0, 0};
	int (*print_func)(va_list, flags_t *);

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	for (str = format; *str != '\0'; ++str)
	{
		if (*str == '%')
		{
			++str;
			if (*str == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*str, &flags))
				++str;
			print_func = get_print(*str);
			count += (print_func)
				? print_func(arg, &flags)
				: _printf("%%%c", *str);
		} else
		{
			count += _putchar(*str);
		}
	}
	_putchar(-1);
	va_end(arg);
	return (count);
}
