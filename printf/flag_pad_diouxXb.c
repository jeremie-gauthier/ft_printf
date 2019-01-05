#include "ft_printf.h"

int			get_pad_val(t_flags *fl, const char c, const char *s, const char *conv)
{
	int		pad_val;

	pad_val = (fl->mo) ? ft_get_flag_value(s, '-') : ft_get_flag_value(s, '1');
	if (c == 'i' || c == 'd')
	{
		if ((fl->sp || fl->pl) && conv && conv[0] != '-')
			pad_val--;
	}
	if ((c == 'o' || c == 'x' || c == 'X' || c == 'b') && fl->dz)
		pad_val -= (c == 'x' || c == 'X' || c == 'b') ? 2 : 1;
	if (pad_val < 0)
		return (0);
	return (pad_val);
}

int			ft_put_zeroes(int pad_val, int len)
{
	int		tmp;

	tmp = len;
	while (len < pad_val)
	{
		ft_putchar('0');
		len++;
	}
	if (pad_val - tmp >= 0)
		return (pad_val - tmp);
	return (0);
}

int			ft_put_spaces(int pad_val, int len)
{
	int		tmp;

	tmp = len;
	while (len < pad_val)
	{
		ft_putchar(' ');
		len++;
	}
	if (pad_val - tmp >= 0)
		return (pad_val - tmp);
	return (0);}

int			ft_precision_format_int(const char *conv, int precis)
{
	int		len;

	len = ft_strlen(conv);
	while (len++ < precis)
		ft_putchar('0');
	ft_putstr_unicode(conv);
	return (len - 1);
}


int			ft_pad_diouxXb(t_flags *fl, const char *conv, const char *s, const char c)
{
	// int		pad_val;
	// int		len;
	// int		precis;
	// int		ret;

	// pad_val = get_pad_val(fl, c, s, conv);
	// len = ft_strlen(conv);
	// precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	// ret = 0;
	if (fl->mo)
	{
		return (ft_pad_diouxXb_right(fl, conv, s, c));
		// fl->f0 = 0;
		// ret = ft_flag_attrs(fl, c, conv);
		// if (fl->pr)
		// 	ret += ft_precision_format((char*)conv, precis, len);
		// else
		// {
		// 	if (conv && *conv == '-')
		// 	{
		// 		ft_putchar(*conv++);
		// 		(fl->pl) ? pad_val++ : 0;
		// 		(fl->pl) ? ret-- : 0;
		// 		fl->pl = 0;
		// 	}
		// 	ft_putstr_unicode(conv);
		// }
		// ret += ft_put_spaces(pad_val, len);
		// return (ret);
	}
	else
	{
		return (ft_pad_diouxXb_left(fl, conv, s, c));
		// if (fl->pr)
		// {
		// 	precis = ((precis < len) ? precis : len);
		// 	if (fl->f0 == 0)
		// 	{
		// 		ret = ft_put_spaces(pad_val, len);
		// 		if (conv && *conv == '-')
		// 		{
		// 			ft_putchar(*conv++);
		// 			(fl->pl) ? pad_val++ : 0;
		// 			fl->pl = 0;
		// 		}
		// 	}
		// 	if (fl->f0 == 1)
		// 	{
		// 		if (conv && *conv == '-')
		// 		{
		// 			ft_putchar(*conv++);
		// 			(fl->pl) ? pad_val++ : 0;
		// 			fl->pl = 0;
		// 			ret = 1;
		// 		}
		// 		ret += ft_put_zeroes(pad_val, len);
		// 	}
		// 	ret += ft_precision_format((char*)conv, precis, len);
		// }
	// 	else
	// 	{
	// 		if (fl->f0 == 0)
	// 		{
	// 			ret += ft_put_spaces(pad_val, len);
	// 			ret += ft_flag_attrs(fl, c, conv);
	// 			if (conv && *conv == '-')
	// 			{
	// 				ft_putchar(*conv++);
	// 				(fl->pl) ? pad_val++ : 0;
	// 				fl->pl = 0;
	// 			}
	// 		}
	// 		if (fl->f0 == 1)
	// 		{
	// 			if (conv && *conv == '-')
	// 			{
	// 				ft_putchar(*conv++);
	// 				(fl->pl) ? pad_val++ : 0;
	// 				fl->pl = 0;
	// 			}
	// 			ret += ft_flag_attrs(fl, c, conv);
	// 			ret += ft_put_zeroes(pad_val, len);
	// 		}
	// 		ft_putstr_unicode(conv);
	// 	}
	// 	return (ret);
	}
	return (0);
}