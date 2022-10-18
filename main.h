#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
  * struct flags - signifies specified flags(s) to _printf
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

/** print prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int _putstr(char *str);
int print_s(va_list arg, flags_t *flag);
int print_c(va_list arg, flags_t *flag);
int print_S(va_list arg, flags_t *flag);
int print_r(va_list arg, flags_t *flag);
int print_R(va_list arg, flags_t *flag);
int print_percent(va_list arg, flags_t *flag);
int print_p(va_list arg, flags_t *flag);

/* get prototypes */
int get_flag(char c, flags_t *flag);
int (*get_print(char c))(va_list, flags_t *);

/**
  * struct print_help - chooses the correct function based on
  * format specifications passed to _printf function
  * @c: Format specification
  * @print_func: Pointer to correct function
  */
typedef struct print_help
{
	char c;
	int (*print_func)(va_list arg, flags_t *flag);
} print_help_t;

/* print number(s) prototypes */
int int_count(int n);
void print_num(int n);
int print_i(va_list arg, flags_t *flag);
char *num_to_str(unsigned long int num, int base, int type);
int print_u(va_list arg, flags_t *flag);
int print_x(va_list arg, flags_t *flag);
int print_X(va_list arg, flags_t *flag);
int print_b(va_list arg, flags_t *flag);
int print_o(va_list arg, flags_t *flag);

#endif /* MAIN_H */
