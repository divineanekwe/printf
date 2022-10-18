#include "main.h"

/**
  * print_s - prints a string
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
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
  * print_c - prints a character
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Return: Always 1
  */
int print_c(va_list arg, __attribute__((unused)) flags_t *flag)
{
	_putchar(va_arg(arg, int));
	return (1);
}
