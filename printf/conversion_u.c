#include "ft_printf.h"

/*
**	Conversion u are call with appropriate function for flag 'h' conversion.
*/

int		ft_conversion_h_u(t_flags *fl, unsigned short int nb, const char *s)
{
	char	*conv;
	int		ret;

	if (nb == 0)
		fl->dz = 0;
	conv = ft_uitoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'u');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'u');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'u', conv);
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'u', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion u are call with appropriate function for flag 'hh' conversion.
*/

int		ft_conversion_hh_u(t_flags *fl, unsigned char nb, const char *s)
{
	char	*conv;
	int		ret;

	if (nb == 0)
		fl->dz = 0;
	conv = ft_uitoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'u');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'u');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'u', conv);
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'u', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion u are call with appropriate function for flag 'l' conversion.
*/

int		ft_conversion_l_u(t_flags *fl, unsigned long int nb, const char *s)
{
	char	*conv;
	int		ret;

	if (nb == 0)
		fl->dz = 0;
	conv = ft_ultoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'u');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'u');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'u', conv);
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'u', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion u are call with appropriate function for flag 'll' conversion.
*/

int		ft_conversion_ll_u(t_flags *fl, unsigned long long int nb, const char *s)
{
	char	*conv;
	int		ret;

	if (nb == 0)
		fl->dz = 0;
	conv = ft_ulltoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'u');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'u');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'u', conv);
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'u', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion u are call with appropriate function for no flag.
*/

int		ft_conversion_u(t_flags *fl, unsigned int nb, const char *s)
{
	char	*conv;
	int		ret;

	if (nb == 0)
		fl->dz = 0;
	conv = ft_uitoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'u');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'u');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'u', conv);
		ret += ft_flag_prec_diouxX(conv, s);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'u', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}