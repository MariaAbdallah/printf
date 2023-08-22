#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_hex(va_list ap, par *pa)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (pa->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pa->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pa);
	if (pa->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	pa->unsign = 1;
	return (c += print_number(str, pa));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_HEX(va_list ap, par *pa)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (pa->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pa->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, pa);
	if (pa->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	pa->unsign = 1;
	return (c += print_number(str, pa));
}
/**
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_binary(va_list ap, par *pa)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, pa);
	int c = 0;

	if (pa->hashtag_flag && n)
		*--str = '0';
	pa->unsign = 1;
	return (c += print_number(str, pa));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_octal(va_list ap, par *pa)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (pa->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pa->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, pa);

	if (pa->hashtag_flag && l)
		*--str = '0';
	pa->unsign = 1;
	return (c += print_number(str, pa));
}
