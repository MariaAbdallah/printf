#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	par pa = PAR_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_par(&pa, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &pa))
		{
			p++;
		}
		p = get_width(p, &pa, ap);
		p = get_precision(p, &pa, ap);
		if (get_modifier(p, &pa))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p, pa.l_modifier || pa.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &pa);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
