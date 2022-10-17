#include "main.h"

/**
  * print_str - prints a string
  * @arg: Variable arguments in _printf
  *
  * Return: Number of characters printed
  */
int print_str(va_list arg)
{
	char *str = va_arg(arg, char *);

	if (!str)
		str = "(null)";
	return (_putstr(str));
}

/**
  * print_char - prints a character
  * @arg: Variable arguments in _printf
  *
  * Return: Always 1
  */
int print_char(va_list arg)
{
	_putchar(va_arg(1, int));
	return (1);
}
