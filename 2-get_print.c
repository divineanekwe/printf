#include "main.h"

/**
  * get_print - selects the correct function to perform
  * the specified formatting on string to print
  * @c: Character for format specifier
  *
  * Description - only the appropriate format specifications
  * are taken into account
  *
  * Return: Pointer to the correct function
  */
int (*get_print(char c))(va_list, flags_t *f)
{
	print_help_t types[] = {
		{'i', print_i},
		{'s', print_s},
		{'c', print_c},
		{'d', print_i},
		{'u', print_u},
		{'x', print_x},
		{'X', print_X},
		{'b', print_b},
		{'o', print_o},
		{'R', print_R},
		{'r', print_r},
		{'S', print_S},
		{'p', print_p},
		{'%', print_percent}
	};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
	{
		if (types[i].c == s)
		{
			return (types[i].f);
		}
	}
	return (NULL);
}
