#include "ft_printf.h"

int			ft_pad_diouxXb_right(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		pad_val;
	int		len;
	int		precis;
	int		ret;

	pad_val = ft_get_flag_value(s, '-');
	len = ft_strlen(conv);
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	fl->f0 = 0;
	ret = 0;
	if (fl->pr)
	{
		if (conv && *conv == '-')
		{
			ft_putchar(*conv++);
			ret++;
			fl->pl = 0;
		}
		ret += ft_flag_attrs(fl, c, conv);
		ret += ft_precision_format_int((char*)conv, precis);
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
	pad_val -= ret;
	if (pad_val < 0)
		pad_val = 0;
	// ft_putnbr(pad_val);
	// if (ret < pad_val)
	//ft_putnbr(ret);
	ret += ft_put_spaces(pad_val, 0);
	// else
	// 	ret += ft_put_spaces(pad_val, len);
	return (ret);
}