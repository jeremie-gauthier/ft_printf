#include "../ft_printf.h"

void	ft_conversion_L_f(t_flags *fl, long double nb, const char *s)
{
	unsigned int	precis;
	char			*conv;

	conv = NULL;
	if (fl->pr == 0)
		conv = ft_ldtoa(nb, 6);
	else if (fl->pr)
	{
		while (!ft_isdigit(*s))
			s++;
		precis = ft_atoi(s);
		conv = ft_ldtoa(nb, precis);
	}
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'f');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'f');
	else
	{
		ft_flag_attrs(fl, 'f');
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

void	ft_conversion_f(t_flags *fl, double nb, const char *s)
{
	unsigned int	precis;
	char			*conv;

	conv = NULL;
	if (fl->pr == 0)
		conv = ft_dtoa(nb, 6);
	else if (fl->pr)
	{
		while (!ft_isdigit(*s))
			s++;
		precis = ft_atoi(s);
		conv = ft_dtoa(nb, precis);
	}
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'f');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'f');
	else
	{
		ft_flag_attrs(fl, 'f');
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}
