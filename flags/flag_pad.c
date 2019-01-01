#include "../ft_printf.h"

int		ft_flag_pad_right(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		padding;
	int		len;
	int		ret;

	ret = 0;
	len = (conv == NULL) ? 1 : ft_strlen(conv);
	if (fl->mo)
	{
		while (*s != '-')
			s++;
	}
	padding = ft_abs(ft_atoi(s + 1)) - len;
	if (c == 'i' || c == 'd')
		padding -= (fl->sp | fl->pl);
	if ((c == 'o' || c == 'x' || c == 'X' || c == 'b') && fl->dz)
		padding -= (c == 'x' || c == 'X' || c == 'b') ? 2 : 1;
	ret = padding + len;
	if (conv)
	{
		ret += ft_flag_attrs(fl, c);
		ft_putstr(conv);
	}
	else if (conv == NULL)
		ft_putchar(c);
	if (padding > 0)
	{
		while (padding--)
			ft_putchar(' ');
	}
	return (ret > len) ? ret : len;
}

int		ft_flag_pad_left(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		padding;
	int		len;
	int		ret;

	ret = 0;
	len = 0;
	if ((fl->mo | fl->pr) == 0)
	{
		len = (conv == NULL) ? 1 : ft_strlen(conv);
		if (fl->f0)
		{
			while (*s != '0')
				s++;
		}
		else
		{
			while (!ft_isdigit(*s))
				s++;
		}
		padding = ft_abs(ft_atoi(s)) - len;
		if (c == 'i' || c == 'd')
			padding -= (fl->sp | fl->pl);
		if ((c == 'o' || c == 'x' || c == 'X') && fl->dz)
			padding -= (c == 'x' || c == 'X') ? 2 : 1;
		ret = padding + len;
		if (padding > 0)
		{
			while (padding--)
				(fl->f0 == 1) ? ft_putchar('0') : ft_putchar(' ');
			if (conv)
			{
				ret += ft_flag_attrs(fl, c);
				ft_putstr(conv);
			}
			else if (conv == NULL)
				ft_putchar(c);
		}
		else if (padding <= 0)
		{
			if (conv)
			{
				ret += ft_flag_attrs(fl, c);
				ft_putstr(conv);
			}
		}
	}
	return (ret > len) ? ret : len;
}