#include "ft_printf.h"

static int	ft_put_padding(int pad_val, int len)
{
	while (len < pad_val)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

static int	ft_precision_format(const char *str, int precis, int len)
{
	char	*dup;

	if (len <= precis)
	{
		ft_putstr_unicode(str);
		return (len);
	}
	dup = ft_strndup(str, precis);
	ft_putstr_unicode(dup);
	ft_strdel(&dup);
	return (precis);
}

int			ft_pad_str(t_flags *fl, const char *str, const char *s)
{
	int		pad_val;
	int		len;
	int		precis;
	int		ret;

	pad_val = (fl->mo) ? ft_get_flag_value(s, '-') : ft_get_flag_value(s, '1');
	len = ft_strlen(str);
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	ret = 0;
	if (fl->mo)
	{
		if (fl->pr)
			len = ft_precision_format((char*)str, precis, len);
		else
			ft_putstr_unicode(str);
		len += ft_put_padding(pad_val, len);
		return (len);
	}
	else
	{
		if (fl->pr)
		{
			precis = ((precis < len) ? precis : len);
			pad_val = ft_put_padding(pad_val, precis);
			len = ft_precision_format((char*)str, precis, len);
		}
		else
		{
			pad_val = ft_put_padding(pad_val, len);
			ft_putstr_unicode(str);
		}
		return (pad_val);
	}
	return (len);
}