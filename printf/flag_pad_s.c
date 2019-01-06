#include "ft_printf.h"

static int	ft_put_padding(t_flags *fl, int pad_val, int len, int precis)
{
	int		tmp;

	len = (fl->pr && len > precis) ? precis : len;
	tmp = len;
	while (len < pad_val)
	{
		(fl->f0) ? ft_putchar('0') : ft_putchar(' ');
		len++;
	}
	return (len - tmp);
}

static int	ft_precision_format(const char *str, int precis, int len)
{
	char	*dup;

	if (ft_strcmp(str, "") == 0)
		return (0);
	if (len <= precis && len != 0)
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
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	len = (fl->pr && precis == 0) ? 0 : ft_strlen(str);
	ret = 0;
	if (fl->mo)
	{
		if (fl->pr)
			ret += ft_precision_format((char*)str, precis, len);
		else
		{
			ret += ft_strlen(str);
			ft_putstr_unicode(str);
		}
		ret += ft_put_padding(fl, pad_val, len, precis);
		return (ret);
	}
	else
	{
		if (fl->pr)
		{
			precis = ((precis < len) ? precis : len);
			ret += ft_put_padding(fl, pad_val, precis, precis);
			ret += ft_precision_format((char*)str, precis, len);
		}
		else
		{
			ret = ft_put_padding(fl, pad_val, len, precis);
			ret += ft_strlen(str);
			ft_putstr_unicode(str);
		}
		return (ret);
	}
	return (ret);
}