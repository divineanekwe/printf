#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct flags - signifies specified flag(s) to _printf
 * @hash: '#' flag
 * @zero: '0' flag
 * @plus: '+' flag
 * @minus: '-' flag
 * @space: ' ' flag
 * @long_l: 'l' flag
 * @short_h: 'h' flag
 * @width: Width flag
 * @unsigned_u: 'u' flag
 * @precision: Precision flag
 */

typedef struct flags
{
	unsigned int width;
	unsigned int hash: 1;
	unsigned int zero: 1;
	unsigned int plus: 1;
	unsigned int minus: 1;
	unsigned int space: 1;
	unsigned int precision;
	unsigned int long_l: 1;
	unsigned int short_h: 1;
	unsigned int unsigned_u: 1;
} flags_t;

/**
 * struct printf_help - chooses the correct function based on
 * format specifications passed to _printf
 * @format: Format specification
 * @print_func: Pointer to correct function
 */
typedef struct printf_help
{
	char *format;
	int (*print_func)(va_list, flags_t *);
} print_help_t;

/* write prototypes */
int _putchar(char c);
int _putstr(char *str);

/* print prototypes */
int _printf(const char *format, ...);
int print_c(va_list arg, flags_t *flag);
int print_s(va_list arg, flags_t *flag);
int print_S(va_list arg, flags_t *flag);
int print_r(va_list arg, flags_t *flag);
int print_R(va_list arg, flags_t *flag);
int print_percent(va_list arg, flags_t *flag);
int print_buffer(char *head, char *tail, char *skip);

/* print number(s) prototypes */
int _isdigit(int n);
int _strlen(char *str);
int print_i(va_list arg, flags_t *flag);
int print_u(va_list arg, flags_t *flag);
int print_p(va_list arg, flags_t *flag);
int print_x(va_list arg, flags_t *flag);
int print_X(va_list arg, flags_t *flag);
int print_b(va_list arg, flags_t *flag);
int print_o(va_list arg, flags_t *flag);
int print_num(char *str, flags_t *flag);
int print_num_left_shift(char *str, flags_t *flag);
int print_num_right_shift(char *str, flags_t *flag);
char *num_to_str(long int num, int base, int flags);

/* get prototypes */
int get_flag(char *str, flags_t *flag);
void init_flags(va_list arg, flags_t *flag);
int get_modifier(char *str, flags_t *flag);
char *get_width(char *str, va_list arg, flags_t *flag);
char *get_precision(char *str, va_list arg, flags_t *flag);
int get_print_func(char *str, va_list arg, flags_t *flag);
int (*get_specifier(char *str))(va_list arg, flags_t *flag);

#endif /* MAIN_H */
