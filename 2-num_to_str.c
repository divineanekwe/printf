#include "main.h"

/**
  * num_to_str - converts an integer in specified base to string
  * @num: Number to be converted
  * @base: Base of the number @num
  * @type: Type of case (lower or upper) for hexadecimal
  *
  * Description - man itoa
  *
  * Return: Pointer to resulting string
  */
char *num_to_str(long int num, int base, int type)
{
	char *str, sign = 0;
	unsigned long n = num;
	static char *hexa_str;
	static char buffer[50];

	if (!(type & 2) && num < 0)
	{
		n = -1 * num;
		sign = '-';
	}
	hexa_str = type & 1 ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';
	do {
		*--str = hexa_str[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
	{
		*--str = sign;
	}
	return (str);
}
