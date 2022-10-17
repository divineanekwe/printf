#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/* print arguments */
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
int get_flag(char s, flags_t *f);

#endif /* MAIN_H */
