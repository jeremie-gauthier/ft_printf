#include "ft_printf.h"

static int	ft_put_padding(t_flags *fl, int pad_val, int len)
{
	while (len < pad_val)
	{
		(fl->f0) ? ft_putchar('0') : ft_putchar(' ');
		len++;
	}
	return (len);
}

static int	ft_precision_format(const unsigned char c, int precis, int len)
{
	// char	*dup;

	if (len <= precis)
	{
		ft_putchar(c);
		return (len);
	}
	// dup = ft_strndup(c, precis);
	// ft_putstr_unicode(dup);
	// ft_strdel(&dup);
	return (precis);
}

int			ft_pad_c(t_flags *fl, const unsigned char c, const char *s)
{
	int		pad_val;
	int		len;
	int		precis;

	pad_val = (fl->mo) ? ft_get_flag_value(s, '-') : ft_get_flag_value(s, '1');
	len = 1;
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	if (fl->mo)
	{
		if (fl->pr)
			ft_precision_format(c, precis, len);
		else
			ft_putchar(c);
		len = ft_put_padding(fl, pad_val, len);
		return (len);
	}
	else
	{
		if (fl->pr)
		{
			precis = ((precis < len) ? precis : len);
			pad_val = ft_put_padding(fl, pad_val, precis);
			len = ft_precision_format(c, precis, len);
		}
		else
		{
			pad_val = ft_put_padding(fl, pad_val, len);
			ft_putchar(c);
		}
		return (pad_val);
	}
	return (len);
}