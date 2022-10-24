#include "main.h"

/**
  * init_flags - initialized flag(s) in _printf to zero
  * @flag: Pointer variable to flags_t type
  * @arg: Variable argument in _printf
  *
  * Return: Void (nothing)
  */
void init_flags(__attribute__((unused)) va_list arg, flags_t *flag)
{
	flag->hash = 0;
	flag->zero = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->space = 0;
	flag->long_l = 0;
	flag->short_h = 0;
	flag->unsigned_u = 0;
	flag->precision = UINT_MAX;
}

/**
  * get_flag - finds specified flag(s) in _printf
  * @str: String to check for flag(s)
  * @flag: Pointer variable to flags_t type
  *
  * Return: 1, if any flag is found.
  * Otherwise, return zero (0)
  */
int get_flag(char *str, flags_t *flag)
{
	int i = 0;

	switch (*str)
	{
		case '#':
			flag->hash = i = 1;
			break;
		case '0':
			flag->zero = i = 1;
			break;
		case '+':
			flag->plus = i = 1;
			break;
		case '-':
			flag->minus = i = 1;
			break;
		case ' ':
			flag->space = i = 1;
			break;
	}
	return (i);
}

/**
  * get_modifier - finds specified modifier(s) in _printf
  * @str: String to check for modifier(s)
  * @flag: Pointer variable to flags_t type
  *
  * Return: 1, if any modifier is found.
  * Otherwise, return zero (0)
  */
int get_modifier(char *str, flags_t *flag)
{
	int i = 0;

	switch (*str)
	{
		case 'l':
			flag->long_l = i = 1;
			break;
		case 'h':
			flag->short_h = i = 1;
			break;
	}
	return (i);
}

/**
  * get_width - finds the width of a format string
  * @str: The format string
  * @flag: Pointer variable to flags_t type
  * @arg: Variable argument in _printf
  *
  * Return: Pointer to remaining characters in string @str
  * skipping the width modifier
  */
char *get_width(char *str, va_list arg, flags_t *flag)
{
	int width = 0;

	if (*str == '*')
	{
		width = va_arg(arg, int);
		str++;
	} else
	{
		while (_isdigit(*str))
		{
			width = width * 10 + (*str++ - '0');
		}
	}
	flag->width = width;
	return (str);
}

/**
  * get_precision - finds the precision of a format string
  * @str: The format string
  * @flag: Pointer variable to flags_t type
  * @arg: Variable argument in _printf
  *
  * Return: Pointer to remaining characters in string @str
  * skipping the precision specifier
  */
char *get_precision(char *str, va_list arg, flags_t *flag)
{
	int precision = 0;

	if (*str != '.')
	{
		return (str);
	}
	str++;
	if (*str == '*')
	{
		precision = va_arg(arg, int);
		str++;
	} else
	{
		while (_isdigit(*str))
		{
			precision = precision * 10 + (*str++ - '0');
		}
	}
	flag->precision = precision;
	return (str);
}
