#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list ap, par *pa)
{
	spec specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @pa: the parameters struct
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, par *pa)
{
	int (*f)(va_list, par *) = get_specifier(s);

	if (f)
		return (f(ap, pa));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @pa: the parameters struct
 * Return: if flag was valid
 */
int get_flag(char *s, par *pa)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = pa->plus_flag = 1;
			break;
		case ' ':
			i = pa->space_flag = 1;
			break;
		case '#':
			i = pa->hashtag_flag = 1;
			break;
		case '-':
			i = pa->minus_flag = 1;
			break;
		case '0':
			i = pa->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @pa: the parameters struct
 * Return: if modifier was valid
 */
int get_modifier(char *s, par *pa)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = pa->h_modifier = 1;
		break;
	case 'l':
		i = pa->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @pa: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
 */
char *get_width(char *s, par *pa, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	pa->width = d;
	return (s);
}
