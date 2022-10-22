#include "main.h"

/**
  * get_specifier - finds the correct print function to perform
  * the specified formatting on a string to print
  * @str: Pointer to character for format specifier
  *
  * Description - only the appropriate format specifications are
  * taken to consideration
  *
  * Return: Pointer to the selected function
  */
int (*get_specifier(char *str))(va_list arg, flags_t *flag)
{
	print_help_t specifiers[15] = {
		{"c", print_c},		/* Character print function */
		{"s", print_s},		/* String print function */
		{"i", print_i},		/* Integer print function */
		{"d", print_i},		/* Decimal print function */
		{"u", print_u},		/* Unsigned print function */
		{"x", print_x},		/* Hexadecmial print function */
		{"X", print_X},		/* Hexadecimal print function (CAPS) */
		{"b", print_b},		/* Binary print function */
		{"o", print_o},		/* Octal print function */
		{"R", print_R},		/* Rot13 print function */
		{"r", print_r},		/* Reverse print function */
		{"S", print_S},		/* Custom non-printable character */
		{"p", print_p},		/* Address print function */
		{"%", print_percent},	/* Percentage (%) print function */
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].format)
	{
		if (*str == specifiers[i].format[0])
		{
			return (specifiers[i].print_func);
		}
		i++;
	}
	return (NULL);
}

/**
  * get_print_func - calls the specified print function
  * @str: The string to print
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int get_print_func(char *str, va_list arg, flags_t *flag)
{
	int (*print_func)(va_list, flags_t *) = get_specifier(str);

	if (print_func)
		return (print_func(arg, flag));
	return (0);
}

/**
  * _printf - prints to stdout using format specifications
  * @format: The format string to print
  *
  * Return: The number of character(s) printed
  */
int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;
	char *str, *head;
	flags_t flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (!format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (str = (char *)format; *str; ++str)
	{
		init_flags(arg, &flags);
		if (*str != '%')
		{
			count += _putchar(*str);
			continue;
		}
		head = str;
		str++;
		while (get_flag(str, &flags))
			++str;
		str = get_width(str, arg, &flags);
		str = get_precision(str, arg, &flags);
		if (get_modifier(str, &flags))
		{
			str++;
		}
		if (!get_specifier(str))
		{
			count += print_buffer(head, str,
					flags.long_l || flags.short_h ? str - 1 : 0);
		} else
		{
			count += get_print_func(str, arg, &flags);
		}
	}
	_putchar(-1);
	va_end(arg);
	return (count);
}
