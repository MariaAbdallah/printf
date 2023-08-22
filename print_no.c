#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @pa: the parameter struct
 * Return: chars printed
 */
int print_number(char *str, par *pa)
{
	unsigned int i = _strlen(str);
	int neg = (!pa->unsign && *str == '-');

	if (!pa->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (pa->precision != UINT_MAX)
		while (i++ < pa->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!pa->minus_flag)
		return (print_number_right_shift(str, pa));
	else
		return (print_number_left_shift(str, pa));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @pa: the parameter struct
 * Return: chars printed
 */
int print_number_right_shift(char *str, par *pa)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (pa->zero_flag && !pa->minus_flag)
		pad_char = '0';
	neg = neg2 = (!pa->unsign && *str == '-');
	if (neg && i < pa->width && pad_char == '0' && !pa->minus_flag)
		str++;
	else
		neg = 0;
	if ((pa->plus_flag && !neg2) ||
		(!pa->plus_flag && pa->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (pa->plus_flag && !neg2 && pad_char == '0' && !pa->unsign)
		n += _putchar('+');
	else if (!pa->plus_flag && pa->space_flag && !neg2 &&
		!pa->unsign && pa->zero_flag)
		n += _putchar(' ');
	while (i++ < pa->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (pa->plus_flag && !neg2 && pad_char == ' ' && !pa->unsign)
		n += _putchar('+');
	else if (!pa->plus_flag && pa->space_flag && !neg2 &&
		!pa->unsign && !pa->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @pa: the parameter struct
 * Return: chars printed
 */
int print_number_left_shift(char *str, par *pa)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (pa->zero_flag && !pa->minus_flag)
		pad_char = '0';
	neg = neg2 = (!pa->unsign && *str == '-');
	if (neg && i < pa->width && pad_char == '0' && !pa->minus_flag)
		str++;
	else
		neg = 0;

	if (pa->plus_flag && !neg2 && !pa->unsign)
		n += _putchar('+'), i++;
	else if (pa->space_flag && !neg2 && !pa->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < pa->width)
		n += _putchar(pad_char);
	return (n);
}
