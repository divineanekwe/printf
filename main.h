#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/** print arguments */
int _printf(const char *format, ...);
int _putchar(char c);
int _putstr(char *str);

/**
  * struct flags - activates specified flag(s) to _printf()
  * @plus: '+' flag
  * @space: ' ' flag
  * @hash: '#' flag
  */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/* get functions */
int get_flag(char str, flags_t *f);
int (*get_print(char c))(va_list, flags_t *f);

/**
  * struct print_help - chooses the correct function based on
  * format specifications passed to _printf function
  * @c: Format specification
  * @f: Pointer to correct function
  */
typedef struct print_help
{
	char c;
	int (*f)(va_list arg, flags_t *f);
} print_help_t;

#endif /* MAIN_H */
