#include "main.h"

/**
  * print_S - prints the string
  * @arg: Variable arguments in _printf
  *
  * Description - non printable characters
  * (0 < ASCII value < 32 or >= 127) are
  * printed this way: \x, followed by the
  * ASCII code value in hexademical
  * (uppercase - alwyas 2 characters)
  *
  * Return: The number of character(s) printed
  */
int print_S(va_list arg, __attribute__((unused)) flags_t *flag)
{
	char *hex_str;
	int i, count = 0;
	char *str = va_arg(arg, char *);

	if (!str)
	{
		return (_putstr("(null)"));
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
		{
			count += _putstr("\\x");
			hex_str = num_to_str(str[i], 16, 0);
			if (!hex_str[1])
				count += _putchar ('0');
			count += _putstr(hex_str);
		} else
		{
			count += _putchar(str[i]);
		}
	}
	return (count);
}

/**
  * print_r - prints a string in reverse
  * @arg: Variable arguments in _printf
  *
  * Return: The number of character(s) printed,
  * including the terminating null charater '\0'
  */
int print_r(va_list arg, __attribute__((unused)) flags_t *flag)
{
	int i, count = 0;
	char *str = va_arg(arg, char *);

	if (!str)
		str = "(null)";
	while (str[count])
		count++;
	for (i = count - 1; i >= 0; --i)
		_putchar(str[i]);
	return (count);
}

/**
  * print_R - prints a string encoded with rot13
  * @arg: Variable arguments in _printf
  *
  * Return: The number of character(s) printed,
  * including the terminating null character '\0'
  */
int print_R(va_list arg, __attribute__((unused)) flags_t *flag)
{
	int i, j;
	char *str = va_arg(arg, char *);
	char c[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char R[53] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; *(str + i) != '\0'; ++i)
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
		{
			_putchar(str[i]);
		} else
		{
			for (j = 0; j < 52; j++)
			{
				if (*(str + i) == *(c + j))
				{
					_putchar(R[j]);
				}
			}
		}
	}
	return (i);
}

/**
  * print_percent - prints a percentage sign
  *
  * Return: Always 1
  */
int print_percent(va_list arg, __attribute__((unused)) flags_t *flag)
{
	(void) arg;
	return (_putchar('%'));
}
