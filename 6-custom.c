#include "main.h"

/**
  * print_percent - prints a percentage sign
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Return: Always 1
  */
int print_percent(va_list arg, __attribute__((unused)) flags_t *flag)
{
	(void)arg;
	return (_putchar('%'));
}

/**
  * print_S - prints a string
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Description - non printable characters (0 < ASCII value < 32 or >= 127)
  * are printed this way: \x, followed by the ASCII code value in hexadecimal
  * (uppercase - always 2 characters)
  *
  * Return: The number of character(s) printed
  */
int print_S(va_list arg, __attribute__((unused)) flags_t *flag)
{
	int count = 0;
	char *hex_str;
	char *str = va_arg(arg, char *);

	if (!str)
	{
		return (_putstr("(null)"));
	}
	for (; *str; ++str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hex_str = num_to_str(*str, 16, 0);
			if (!hex_str[1])
			{
				count += _putchar('0');
			}
			count += _putstr(hex_str);
		} else
		{
			count += _putchar(*str);
		}
	}
	return (count);
}

/**
  * print_r - prints a string in reverse
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_r(va_list arg, __attribute__((unused)) flags_t *flag)
{
	char *str = va_arg(arg, char *);
	int count = 0, len = _strlen(str);

	if (str)
	{
		for (; len > 0; --len)
		{
			count += _putchar(str[len]);
		}
	}
	return (count);
}

/**
  * print_R - prints a string encoded with rot13
  * @arg: Variable argument in _printf
  * @flag: Pointer variable to flags_t type
  *
  * Return: The number of character(s) printed
  */
int print_R(va_list arg, __attribute__((unused)) flags_t *flag)
{
	int i, j, count = 0;
	char *str = va_arg(arg, char *);
	char c[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char R[53] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; *(str + i); ++i)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') ||
				(str[i] >= 'a' && str[i] <= 'z'))
		{
			for (j = 0; j < 52; j++)
			{
				if (*(str + i) == *(c + j))
				{
					count += _putchar(R[j]);
					break;
				}
			}
		} else
		{
			count += _putchar(str[i]);
		}
	}
	return (count);
}
