#include "../ft_printf.h"

/*
**	For flag conversion, call the good function with good type.
*/

void			ft_type_conv(t_flags *fl, va_list ap, char c)
{
	if (fl->hh) //signed ou uns. char
	{
		if (c == 'i' || c == 'd')
			ft_conversion_hh_i_d(fl, va_arg(ap, int));
		else
			start_uns_char_conv(fl, va_arg(ap, int), c);
	}
	else if (fl->h) //signed ou uns. short
	{
		if (c == 'i' || c == 'd')
			ft_conversion_h_i_d(fl, va_arg(ap, int));
		else
			start_uns_short_conv(fl, va_arg(ap, int), c);
	}
	else if (fl->l) //signed ou uns. long
	{
		if (c == 'i' || c == 'd')
			ft_conversion_l_i_d(fl, va_arg(ap, long int));
		else
			start_uns_long_conv(fl, va_arg(ap, unsigned long int), c);
	}
	else if (fl->ll) // signed ou uns. long long
	{
		if (c == 'i' || c == 'd')
			ft_conversion_ll_i_d(fl, va_arg(ap, long long int));
		else
			start_uns_long_long_conv(fl, va_arg(ap, unsigned long long int), c);
	}
	else if (fl->L) // long double
	{
		if (c == 'f')
			start_long_double_conv(fl, va_arg(ap, long double));
	}
}
