#include "main.h"

/**
  * get_flag - activates specified flag in _printf()
  * @c: Character flag
  * @f: Pointer variable with flags_t type
  *
  * Return: 1, if a flag is activated.
  * Otherwise, return 0
  */
int get_flag(char c, flags_t *f)
{
	int i = 0;

	switch (c)
	{
		case '+':
			i = 1;
			f->plus = i;
			break;
		case ' ':
			i = 1;
			f->space = i;
			break;
		case '#':
			i = 1;
			f->hash = i;
			break;
	}
	return (i);
}
