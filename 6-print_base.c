#include "main.h"

/**
  * print_x - prints a number in hexadecimal (base 16)
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Description - the hexadecimal is printed in lowercase
  *
  * Return: The number of character(s) printed
  */
int print_x(va_list arg, flags_t *flag)
{
	int count = 0;
	unsigned int n = va_arg(arg, unsigned int);
	char *str = num_to_str(n, 16, 1);

	if (flag->hash == 1 && str[0] != '0')
		count += _putstr("0x");
	count += _putstr(str);
	return (count);
}

/**
  * print_X - prints a number in hexadecimal (base 16)
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Description - the hexadecimal is printed in uppercase
  *
  * Return: The number of character(s) printed
  */
int print_X(va_list arg, flags_t *flag)
{
	int count = 0;
	unsigned int n = va_arg(arg, unsigned int);
	char *str = num_to_str(n, 16, 1);

	if (flag->hash == 1 && str[0] != '0')
		count += _putstr("0X");
	count += _putstr(str);
	return (count);
}

/**
  * print_b - prints a number in binary (base 2)
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_b(va_list arg, __attribute__((unused)) flags_t *flag)
{
	unsigned int n = va_arg(arg, unsigned int);
	char *str = num_to_str(n, 2, 0);

	return (_putstr(str));
}

/**
  * print_o - prints a number in octal (base 8)
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_o(va_list arg, flags_t *flag)
{
	int count = 0;
	unsigned int n = va_arg(arg, unsigned int);
	char *str = num_to_str(n, 8, 0);

	if (flag->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _putstr(str);
	return (count);
}
