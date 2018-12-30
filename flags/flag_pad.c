#include "../ft_printf.h"

void	ft_flag_pad_right(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		padding;
	size_t	len;

	len = ft_strlen(conv);
	if (fl->mo)
	{
		while (*s != '-')
			s++;
	}
	padding = ft_atoi(s + 1) - ((fl->sp | fl->pl) + len);
	if (fl->dz)
		padding -= (c == 'x' || c == 'X') ? 2 : 1;
	if (conv)
	{
		ft_flag_attrs(fl, c, conv);
		ft_putstr(conv);
	}
	if (padding > 0)
	{
		while (padding--)
			ft_putchar(' ');
	}
}

void	ft_flag_pad_left(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		padding;
	size_t	len;

	if ((fl->mo | fl->pr) == 0)
	{
		len = ft_strlen(conv);
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
		padding = ft_atoi(s) - ((fl->sp | fl->pl) + len);
		if (fl->dz)
			padding -= (c == 'x' || c == 'X') ? 2 : 1;
		if (padding > 0)
		{
			while (padding--)
				(fl->f0 == 1) ? ft_putchar('0') : ft_putchar(' ');
			if (conv)
			{
				ft_flag_attrs(fl, c, conv);
				ft_putstr(conv);
			}
		}
		else if (padding <= 0)
		{
			if (conv)
			{
				ft_flag_attrs(fl, c, conv);
				ft_putstr(conv);
			}
		}
	}
}