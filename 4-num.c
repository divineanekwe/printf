#include "main.h"

/**
  * print_i - prints an integer
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_i(va_list arg, flags_t *flag)
{
	long num;

	if (flag->long_l)
		num = va_arg(arg, long);
	else if (flag->short_h)
		num = (short int)va_arg(arg, int);
	else
		num = (int)va_arg(arg, int);
	return (print_num(num_to_str(num, 10, 0), flag));
}

/**
  * print_u - prints an unsigned integer
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_u(va_list arg, flags_t *flag)
{
	unsigned long num;

	if (flag->long_l)
		num = (unsigned long)va_arg(arg, unsigned long);
	else if (flag->short_h)
		num = (unsigned short int)va_arg(arg, unsigned int);
	else
		num = (unsigned int)va_arg(arg, unsigned int);
	flag->unsigned_u = 1;
	return (print_num(num_to_str(num, 10, 2), flag));
}

/**
  * print_p - prints an address in hexadecimal
  * @arg: Variable arguments in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_p(va_list arg, flags_t *flag)
{
	char *str;
	unsigned long int num = va_arg(arg, unsigned long int);

	if (!num)
		return (_putstr("(nil)"));
	str = num_to_str(num, 16, 2 | 1);
	*--str = 'x';
	*--str = '0';
	return (print_num(str, flag));
}
