#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/** print prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int _putstr(char *str);
int print_str(va_list arg);
int print_char(va_list arg);

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

/* get prototypes */
int get_flag(char c, flags_t *f);
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

/* print number(s) prototypes */
int int_count(int n);
void print_num(int n);
int print_i(va_list arg, flags_t *f);
char *num_to_str(unsigned long int num, int base, int type);
int print_u(va_list arg);
int print_x(va_list arg, flags_t *f);
int print_X(va_list arg, flags_t *f);
int print_b(va_list arg);
int print_o(va_list arg, flags_t *f);

#endif /* MAIN_H */
