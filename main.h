#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

<<<<<<< HEAD
/* print arguments */
=======
/** print prototypes */
>>>>>>> d4fd47d3cb10f59de880ac793d5ee8e100acdab4
int _printf(const char *format, ...);
<<<<<<< HEAD
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****** FUNCTIONS ******/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/Function to print string in reverse/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/Function to print a string in rot 13/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****** UTILS ******/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
=======
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
int get_flag(char s, flags_t *f);
>>>>>>> b926342f0d0c1ea37b3191d6cf4a3c5fb52d2ca8

#endif
