#include "main.h"

/**
  * get_flag - signifies specified flag in _printf
  * @c: Character flag
  * @flag: Pointer variable to flags_t type
  *
  * Return: 1, if a flag is signified.
  * Otherwise, return 0
  */
int get_flag(char c, flags_t *flag)
{
	int i = 0;

	switch (c)
	{
		case '+':
			i = 1;
			flag->plus = i;
			break;
		case ' ':
			i = 1;
			flag->space = i;
			break;
		case '#':
			i = 1;
			flag->hash = i;
			break;
	}
	return (i);
}
