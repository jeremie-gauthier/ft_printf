#include "ft_printf.h"

int		ft_flag_prec_diouxX(t_flags *fl, char *conv, const char *s)
{
	unsigned int	precis;
	int				sign;
	size_t			len;

	sign = (conv && *conv == '-') ? 1 : 0;
	if (conv && *conv == '-')
		ft_putchar(*conv++);
	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(conv);
	if (precis > len)
	{
		while (len++ < precis)
			ft_putchar('0');
		ft_putstr(conv);
		return (precis + sign);
	}
	else if (precis <= len)
	{
		if (ft_strcmp(conv, "0") == 0)
		{
			if (fl->pad)		//"@moulitest: %.x %.0x", 0, 0 [47]
				ft_putchar(' '); // "@moulitest: %5.x %5.0x", 0, 0 [48]
			len--;
		}
		else
			ft_putstr_unicode(conv);
		// (ft_strcmp(conv, "0") == 0) ? 0 : ft_putstr_unicode(conv);
		// len--;
	}
	return (len + sign);
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
