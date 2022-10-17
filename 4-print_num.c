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

	if (i < 0)
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
  * @f: Pointer to flags_t type
  *
  * Return: Number of characters printed
  */
int print_i(va_list arg, flags_t *f)
{
	int n = va_arg(arg, int);
	int count = int_count(n);

	if (f->plus == 0 && f->space == 1 && n >= 0)
		count += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		count += _putchar('+');
	if (n <= 0)
		++count;
	print_num(n);
	return (count);
}
