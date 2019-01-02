#include "ft_printf.h"

int		ft_conversion_L_f(t_flags *fl, long double nb, const char *s)
{
	unsigned int	precis;
	char			*conv;
	int				ret;

	conv = NULL;
	if (fl->pr == 0)
	{
		conv = ft_ldtoa(nb, 6);
		ret = ft_strlen(conv);
	}
	else if (fl->pr)
	{
		while (!ft_isdigit(*s))
			s++;
		precis = ft_atoi(s);
		conv = ft_ldtoa(nb, precis);
		ret = ft_strlen(conv);
	}
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'f');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'f');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'f');
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'f');
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

int		ft_conversion_f(t_flags *fl, double nb, const char *s)
{
	unsigned int	precis;
	char			*conv;
	int				ret;

	conv = NULL;
	if (fl->pr == 0)
	{
		conv = ft_dtoa(nb, 6);
		ret = ft_strlen(conv);
	}
	else if (fl->pr)
	{
		while (!ft_isdigit(*s))
			s++;
		precis = ft_atoi(s);
		conv = ft_dtoa(nb, precis);
		ret = ft_strlen(conv);
	}
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'f');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'f');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'f');
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'f');
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}
