#include "main.h"

/**
 * init_par - clears struct fields and reset buf
 * @pa: the parameters struct
 * @ap: the argument pointer
 * Return: void
 */
void init_par(par *pa, va_list ap)
{
	pa->unsign = 0;

	pa->plus_flag = 0;
	pa->space_flag = 0;
	pa->hashtag_flag = 0;
	pa->zero_flag = 0;
	pa->minus_flag = 0;

	pa->width = 0;
	pa->precision = UINT_MAX;

	pa->h_modifier = 0;
	pa->l_modifier = 0;
	(void)ap;
}
