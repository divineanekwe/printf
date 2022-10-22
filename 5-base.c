#include "main.h"

/**
  * print_x - prints a number in hexadecimal (base 16)
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Description - the hexadecimal is printed in lowercase
  *
  * Return: The number of character(s) printed
  */
int print_x(va_list arg, flags_t *flag)
{
	char *str;
	unsigned long num;

	if (flag->long_l)
		num = (unsigned long)va_arg(arg, unsigned long);
	else if (flag->short_h)
		num = (unsigned short int)va_arg(arg, unsigned int);
	else
		num = (unsigned int)va_arg(arg, unsigned int);
	str = num_to_str(num, 16, 2 | 1);
	if (flag->hash && num)
	{
		*--str = 'x';
		*--str = '0';
	}
	flag->unsigned_u = 1;
	return (print_num(str, flag));
}

/**
  * print_X - prints a number in hexadecimal (base 16)
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Description - the hexadecimal is printed in uppercase
  *
  * Return: The number of character(s) printed
  */
int print_X(va_list arg, flags_t *flag)
{
	char *str;
	unsigned long num;

	if (flag->long_l)
		num = (unsigned long)va_arg(arg, unsigned long);
	else if (flag->short_h)
		num = (unsigned short int)va_arg(arg, unsigned int);
	else
		num = (unsigned int)va_arg(arg, unsigned int);
	str = num_to_str(num, 16, 2);
	if (flag->hash && num)
	{
		*--str = 'X';
		*--str = '0';
	}
	flag->unsigned_u = 1;
	return (print_num(str, flag));
}

/**
  * print_b - prints a number in binary (base 2)
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_b(va_list arg, flags_t *flag)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *str = num_to_str(num, 2, 2);

	if (flag->hash && num)
		*--str = '0';
	flag->unsigned_u = 1;
	return (print_num(str, flag));
}

/**
  * print_o - prints a number in octal (base 8)
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_type
  *
  * Return: The numbe of character(s) printed
  */
int print_o(va_list arg, flags_t *flag)
{
	char *str;
	unsigned long num;

	if (flag->long_l)
		num = (unsigned long)va_arg(arg, unsigned long);
	else if (flag->short_h)
		num = (unsigned short int)va_arg(arg, unsigned int);
	else
		num = (unsigned int)va_arg(arg, unsigned int);
	str = num_to_str(num, 8, 2);
	if (flag->hash && num)
		*--str = '0';
	flag->unsigned_u = 1;
	return (print_num(str, flag));
}
