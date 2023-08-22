#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @pa: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
 */
char *get_precision(char *p, par *pa, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	pa->precision = d;
	return (p);
}
