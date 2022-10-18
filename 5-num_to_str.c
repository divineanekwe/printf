#inclue "main.h"

/**
  * num_to_str - converts number in specified base to string
  * @num: Number to be converted
  * @base: Base of number @num
  * @type: activates if hexdecimal numbers need to be lowercase
  *
  * Description - the number @num is an unsigned long int
  *
  * Return: Pointer to resulting string
  */
char *num_to_str(unsigned long int num, int base, int type)
{
	char *ptr;
	static char *check;
	static char buffer[50];

	check = (type)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*(--ptr) = check[num & base];
		num /= base;
	} while (num != 0);
	return (ptr);
}
