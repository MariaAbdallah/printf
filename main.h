#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PAR_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 * @unsign: flag if unsigned value
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 * @width: field width specified
 * @precision: field precision specified
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} par;

/**
 * struct specifier - Struct token
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, par *);
} spec;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, par *pa);
int print_int(va_list ap, par *pa);
int print_string(va_list ap, par *pa);
int print_percent(va_list ap, par *pa);
int print_S(va_list ap, par *pa);

/* number.c module */
char *convert(long int num, int base, int flags, par *pa);
int print_unsigned(va_list ap, par *pa);
int print_address(va_list ap, par *pa);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, par *pa);
int get_print_func(char *s, va_list ap, par *pa);
int get_flag(char *s, par *pa);
int get_modifier(char *s, par *pa);
char *get_width(char *s, par *pa, va_list ap);

/* convert_number.c module */
int print_hex(va_list ap, par *pa);
int print_HEX(va_list ap, par *pa);
int print_binary(va_list ap, par *pa);
int print_octal(va_list ap, par *pa);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, par *pa);
int print_rot13(va_list ap, par *pa);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, par *pa);
int print_number_right_shift(char *str, par *pa);
int print_number_left_shift(char *str, par *pa);

/* params.c module */
void init_par(par *pa, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, par *pa, va_list ap);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif