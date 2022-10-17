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
		write(1, &buffer, i);
		i = 0;
	}
	if (c != -1)
	{
		buffer[i] = c;
		i++;
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
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
