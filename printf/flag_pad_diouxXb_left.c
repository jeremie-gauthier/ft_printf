#include "ft_printf.h"

static int	deal_with_negative(t_flags *fl, const char **conv, int pad_val)
{
	int	ret;

	ret = 0;
	if (conv && *conv && **conv == '-')
	{
		ft_putchar(**conv);
		*conv += 1;
		(fl->pl) ? pad_val++ : 0;
		fl->pl = 0;
		ret = 1;
	}
	return (ret);
}

static int	ft_put_spaces_pr(int pad_val, int precis, int len, const char *conv)
{
	int		tmp;

	// ft_putnbr(pad_val);
	// BOUCLE A
	if (ft_strcmp(conv, "0") == 0 && precis == 0)
	{
		// ft_putstr("A");
		tmp = 0;
		// precis = len;
		while (precis < pad_val)
		{
			ft_putchar(' ');
			precis++;
		}
	}
	// BOUCLE B
	else
	{
		// ft_putstr("B");
		precis = (precis > len) ? precis : len;
		tmp = precis;
		if (pad_val < precis)
			return (0);
		while (precis < pad_val)
		{
			ft_putchar(' ');
			precis++;
		}
	}
	return (pad_val - tmp);
}

static int	pad_pr(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		pad_val;
	int		len;
	int		precis;
	int		ret;
	int		sign;

	sign = (*conv == '-') ? 1 : 0;
	pad_val = get_pad_val(fl, c, s, conv);
	len = ft_strlen(conv);
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	ret = 0;
	// ft_putnbr(precis);
	if (pad_val > precis + sign)
		ret += ft_put_spaces_pr(pad_val, precis, len, conv);

	// if (precis > pad_val)
	// 	ret += ft_put_zeroes(pad_val, len);
	// else if (precis <= pad_val)
	// {
	// 	precis = ((precis > len) ? precis : len);
	// 	ret += ft_put_spaces(pad_val - precis, 0);
	// }
	ret += ft_flag_attrs(fl, c, conv);
	ret += deal_with_negative(fl, &conv, pad_val);
	ret += ft_precision_format_int((char*)conv, precis);
	// ft_putstr("ici");
	return (ret);
}

// int			ft_put_spaces_left(int pad_val, int len)
// {
// 	int		tmp;

// 	tmp = len;
// 	while (pad_val > len && pad_val > 0)
// 	{
// 		ft_putchar(' ');
// 		pad_val--;
// 	}
// 	return (tmp - pad_val);
// }

static int	pad_no_pr(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		pad_val;
	int		len;
	int		precis;
	int		ret;

	pad_val = get_pad_val(fl, c, s, conv);
	len = ft_strlen(conv);
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	ret = 0;
	if (fl->f0 == 0)
	{
		ret += ft_put_spaces(pad_val, len);
		ret += deal_with_negative(fl, &conv, pad_val);
		ret += ft_flag_attrs(fl, c, conv);
		ft_putstr_unicode(conv);
	}
	else if (fl->f0 == 1)
	{
		ret += deal_with_negative(fl, &conv, pad_val);
		ret += ft_flag_attrs(fl, c, conv);
		ret += ft_put_zeroes(pad_val, len);
		ft_putstr_unicode(conv);
	}
	ret += ft_strlen(conv);
	return (ret);
}

int			ft_pad_diouxXb_left(t_flags *fl, const char *conv, const char *s, const char c)
{
	if (fl->pr)
	{
		fl->f0 = 0;
		return (pad_pr(fl, conv, s, c));
	}
	return (pad_no_pr(fl, conv, s ,c));
}