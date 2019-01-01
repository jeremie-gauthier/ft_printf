#include "ft_printf.h"

/*
**	Conversion x are call with appropriate function for flag 'h' conversion.
*/

int		ft_conversion_h_xmin(t_flags *fl, unsigned short int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_strlowcase(ft_uitoa_base(nb, 16));
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'x');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'x');
	else
	{
		if (nb != 0)
			ret += ft_flag_attrs(fl, 'x');
		if (conv)
			ft_putstr_unicode(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion x are call with appropriate function for flag 'hh' conversion.
*/

int		ft_conversion_hh_xmin(t_flags *fl, unsigned char nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_strlowcase(ft_uitoa_base(nb, 16));
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'x');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'x');
	else
	{
		if (nb != 0)
			ret += ft_flag_attrs(fl, 'x');
		if (conv)
			ft_putstr_unicode(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion x are call with appropriate function for flag 'l' conversion.
*/

int		ft_conversion_l_xmin(t_flags *fl, unsigned long int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_strlowcase(ft_ultoa_base(nb, 16));
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'x');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'x');
	else
	{
		if (nb != 0)
			ret += ft_flag_attrs(fl, 'x');
		if (conv)
			ft_putstr_unicode(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion x are call with appropriate function for flag 'll' conversion.
*/

int		ft_conversion_ll_xmin(t_flags *fl, unsigned long long int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_strlowcase(ft_ulltoa_base(nb, 16));
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'x');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'x');
	else
	{
		if (nb != 0)
			ret += ft_flag_attrs(fl, 'x');
		if (conv)
			ft_putstr_unicode(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion x are call with appropriate function for no flag.
*/

int		ft_conversion_xmin(t_flags *fl, uintptr_t nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_strlowcase(ft_uitoa_base(nb, 16));
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'x');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'x');
	else if (fl->pr)
		ret = ft_flag_prec_diouxX(conv, s);
	else
	{
		if (nb != 0)
			ret += ft_flag_attrs(fl, 'x');
		if (conv)
			ft_putstr_unicode(conv);
	}
	free(conv);
	return (ret);
}