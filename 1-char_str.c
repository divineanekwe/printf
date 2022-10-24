#include "main.h"

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  *
  * Description - _putchar uses a buffer of 1024
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately
  */
int _putchar(char c)
{
	static int i;
	static char buffer[1024];

	if (c == -1 || i >= 1024)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != -1)
	{
		buffer[i++] = c;	/* buffer[i] = c; i++; */
	}
	return (1);
}

/**
  * _putstr - writes the string str to stdout
  * @str: The string to print
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately
  */
int _putstr(char *str)
{
	char *ptr = str;

	while (*str)
		_putchar(*str++);
	return (str - ptr);
}

/**
  * print_c - prints a character
  * @arg: Variable arguments in _printf
  * @flag: Pointer to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_c(va_list arg, flags_t *flag)
{
	unsigned int count = 0, width = 1, c = va_arg(arg, int);

	if (flag->minus)
		count += _putchar(c);
	while (width++ < flag->width)
		count += _putchar(' ');
	if (!flag->minus)
		count += _putchar(c);
	return (count);
}

/**
  * print_s - prints a string
  * @arg: Variable argument in _printf
  * @flag: Pointer to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_s(va_list arg, flags_t *flag)
{
	unsigned int count = 0, width = 0, i = 0, j;
	char *str = va_arg(arg, char *);

	switch ((int)!str)
	case 1:
		str = "(null)";
	width = j = _strlen(str);
	if (flag->precision < width)
		width = j = flag->precision;
	if (flag->minus)
	{
		if (flag->precision != UINT_MAX)
		{
			for (i = 0; i < width; ++i)
			{
				count += _putchar(*str++);
			}
		} else
		{
			count += _putstr(str);
		}
	}
	while (j++ < flag->width)
	{
		count += _putchar(' ');
	}
	if (!flag->minus)
	{
		if (flag->precision != UINT_MAX)
		{
			for (i = 0; i < width; ++i)
			{
				count += _putchar(*str++);
			}
		} else
		{
			count += _putstr(str);
		}
	}
	return (count);
}

/**
  * print_buffer - prints a range of character pointer(s)
  * @head: Address to start printing from
  * @tail: Address to stop printing at
  * @skip: Address to skip printing from
  *
  * Return: The number of character(s) printed
  */
int print_buffer(char *head, char *tail, char *skip)
{
	int count = 0;

	while (head <= tail)
	{
		if (head != skip)
		{
			count += _putchar(*head);
		}
		head++;
	}
	return (count);
}
