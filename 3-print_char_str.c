#include "main.h"

/**
  * print_str - prints a string
  * @arg: Variable arguments in _printf
  *
  * Return: Number of characters printed
  */
int print_s(va_list arg, __attribute__((unused)) flags_t *flag)
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
int print_c(va_list arg, __attribute__((unused)) flags_t *flag)
{
	_putchar(va_arg(arg, int));
	return (1);
}
