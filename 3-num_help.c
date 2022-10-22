#include "main.h"

/**
  * _isdigit - checks if a character is a digit
  * @c: The character to check
  *
  * Return: 1, if the character @c is a digit
  * Otherwise, return 0
  */
int _isdigit(int c)
{
	if (c >= 48 && c < 58)
		return (1);
	return (0);
}

/**
  * _strlen - returns the length of a string
  * @str: String to find its length
  *
  * Return: The length of string @str
  */
int _strlen(char *str)
{
	if (*str)
		return (1 + _strlen(str + 1));
	return (0);
}

/**
  * print_num - prints a number format specification(s)
  * @str: Number to print
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_num(char *str, flags_t *flag)
{
	unsigned int i = _strlen(str);
	int neg = !flag->unsigned_u && *str == '-';

	if (!flag->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (!flag->minus)
		return (print_num_right_shift(str, flag));
	return (print_num_left_shift(str, flag));
}

/**
  * print_num_right_shift - prints a number right justified
  * @str: Number to print
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_num_right_shift(char *str, flags_t *flag)
{
	char fill = ' ';
	unsigned int neg, neg2, count = 0, i = _strlen(str);

	if (flag->zero && !flag->minus)
		fill = '0';
	neg = neg2 = (!flag->unsigned_u && *str == '-');
	if (neg && i < flag->width && fill == '0' && !flag->minus)
		str++;
	else
		neg = 0;
	if ((flag->plus && !neg2) || (!flag->plus && flag->space && !neg2))
		i++;
	if (neg && fill == '0')
		count += _putchar('-');
	if (flag->plus && !neg2 && fill == '0' && !flag->unsigned_u)
		count += _putchar('+');
	else if (!flag->plus && flag->space && !neg2 && !flag->unsigned_u
			&& flag->zero)
		count += _putchar(' ');
	while (i++ < flag->width)
		count += _putchar(fill);
	if (neg && fill == ' ')
		count += _putchar('-');
	if (flag->plus && !neg2 && fill == ' ' && !flag->unsigned_u)
	{
		count += _putchar('+');
	} else if (!flag->plus && flag->space && !neg2 && !flag->unsigned_u
			&& !flag->zero)
		count += _putchar(' ');
	count += _putstr(str);
	return (count);
}

/**
  * print_num_left_shift - prints a number left justified
  * @str: Number to print
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_num_left_shift(char *str, flags_t *flag)
{
	char fill = ' ';
	unsigned int neg, neg2, count = 0, i = _strlen(str);

	if (flag->zero && !flag->minus)
	{
		fill = '0';
	}
	neg = neg2 = !flag->unsigned_u && *str == '-';
	if (neg && i < flag->width && fill == '0' && !flag->minus)
	{
		str++;
	} else
	{
		neg = 0;
	}
	if (flag->plus && !neg2 && !flag->unsigned_u)
	{
		count += _putchar('+'), i++;
	} else if (flag->space && !neg2 && !flag->unsigned_u)
	{
		count += _putchar(' '), i++;
	}
	count += _putstr(str);
	while (i++ < flag->width)
	{
		count += _putchar(fill);
	}
	return (count);
}
