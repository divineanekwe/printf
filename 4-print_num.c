#include "main.h"

/**
  * int_count - finds the number of digits in an integer number
  * @n: Integer number to count
  *
  * Return: Number of digits in the integer @i
  */
int int_count(int n)
{
	unsigned int num, count = 0;

	if (n < 0)
	{
		num = -1 * n;
	} else
	{
		num = n;
	}
	while (num != 0)
	{
		num /= 10;
		++count;
	}
	return (count);
}

/**
  * print_num - prints an integer number
  * @n: Integer number to be printed
  *
  * Return: Void (nothing)
  */
void print_num(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -1 * n;
	} else
	{
		num = n;
	}
	if (num / 10)
	{
		print_num(num / 10);
	}
	_putchar('0' + (num % 10));
}

/**
  * print_i - prints an integer number
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Return: Number of characters printed
  */
int print_i(va_list arg, flags_t *flag)
{
	int n = va_arg(arg, int);
	int count = int_count(n);

	if (flag->plus == 0 && flag->space == 1 && n >= 0)
		count += _putchar(' ');
	if (flag->plus == 1 && n >= 0)
		count += _putchar('+');
	if (n <= 0)
		++count;
	print_num(n);
	return (count);
}

/**
  * print_u - prints an unsigned integer
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Return: Number of characters printed
  */
int print_u(va_list arg, __attribute__((unused)) flags_t *flag)
{
	unsigned int n = va_arg(arg, unsigned int);
	char *str = num_to_str(n, 10, 0);

	return (_putstr(str));
}

/**
  * print_p - prints the address of a variable in hexadecimal
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Description - the hexadecimal is printed in uppercase
  *
  * Return: The number of character(s) printed
  */
int print_p(va_list arg, __attribute__((unused)) flags_t *flag)
{
	register int count = 0;
	char *str;
	unsigned long int addr = va_arg(arg, unsigned long int);

	if (!addr)
		return (_putstr("(nil)"));
	str = num_to_str(addr, 16, 1);
	count += _putstr("0x");
	count += _putstr(str);
	return (count);
}
