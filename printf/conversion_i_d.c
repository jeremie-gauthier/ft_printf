#include "ft_printf.h"

/*
**	Conversion i and d are call with appropriate function for flag 'h' conversion.
*/

int		ft_conversion_h_i_d(t_flags *fl, short int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_itoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i');
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i');
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion i and d are call with appropriate function for flag 'hh' conversion.
*/

int		ft_conversion_hh_i_d(t_flags *fl, char nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_itoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i');
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i');
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion i and d are call with appropriate function for flag 'l' conversion.
*/

int		ft_conversion_l_i_d(t_flags *fl, long int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_ltoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i');
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i');
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion i and d are call with appropriate function for flag 'll' conversion.
*/

int		ft_conversion_ll_i_d(t_flags *fl, long long int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_lltoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i');
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i');
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion i and d are call with appropriate function when no flag is found.
*/

int		ft_conversion_i_d(t_flags *fl, int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_itoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i');
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i');
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}