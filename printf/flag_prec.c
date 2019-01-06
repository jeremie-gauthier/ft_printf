#include "ft_printf.h"

int		ft_flag_prec_diouxX(t_flags *fl, char *conv, const char *s, const char c)
{
	int		precis;
	int		sign;
	int		len;
	int		ret;

	sign = (conv && *conv == '-') ? 1 : 0;
	if (conv && *conv == '-')
		ft_putchar(*conv++);
	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(conv);
	ret = ft_flag_attrs(fl, c, conv);
	precis -= ret;
	if (precis > len)
	{
		while (len++ < precis)
			ft_putchar('0');
		ft_putstr(conv);
		return (precis + ret + sign);
	}
	else if (precis <= len)
	{
		len--;
		if (ft_strcmp(conv, "0") == 0 && precis == 0 && c != 'o')
		{
			if (fl->pad)
				ft_putchar(' ');
		}
		else if (ft_strlen(conv) != 1 || ft_strcmp(conv, "0") != 0)
		{
			len++;
			ft_putstr_unicode(conv);
		}
	}
	// ft_putnbr(ret);
	return (len + sign + ret);
}

int		ft_flag_prec_s(char *str, const char *s)
{
	unsigned int	precis;
	size_t			len;
	char			*dup;

	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(str);
	if (precis < len)
	{
		dup = ft_strndup(str, precis);
		ft_putstr_unicode(dup);
		ft_strdel(&dup);
		return (precis);
	}
	else if (precis >= len)
		ft_putstr(str);
	return (len);
}
