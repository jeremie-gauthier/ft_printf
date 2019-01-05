#include "ft_printf.h"

int			ft_pad_diouxXb_right(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		pad_val;
	int		len;
	int		precis;
	int		ret;

	pad_val = get_pad_val(fl, c, s, conv);
	len = ft_strlen(conv);
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	fl->f0 = 0;
	ret = 0;
	if (fl->pr)
	{
		if (conv && *conv == '-')
		{
			ft_putchar(*conv++);
			// (fl->pl) ? pad_val++ : 0;
			ret++;
			fl->pl = 0;
		}
		ret += ft_flag_attrs(fl, c, conv);
		ret += ft_precision_format_int((char*)conv, precis);
		ft_putnbr(len);
		if (precis > pad_val)
			pad_val -= len;
	}
	else
	{
		ret += ft_flag_attrs(fl, c, conv);
		ret += ft_strlen(conv);
		if (conv && *conv == '-')
		{
			ft_putchar(*conv++);
			(fl->pl) ? pad_val++ : 0;
			(fl->pl) ? ret-- : 0;
			fl->pl = 0;
		}
		ft_putstr_unicode(conv);
	}
	ret += ft_put_spaces(pad_val, len);
	return (ret);
}