#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*functions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

#endif /* MAIN_H */
