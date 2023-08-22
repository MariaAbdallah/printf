#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list);

/*functions to print chars and strings */
int print_char(va_list types);
int print_string(va_list types);
int print_percent(va_list types);

#endif /* MAIN_H */
