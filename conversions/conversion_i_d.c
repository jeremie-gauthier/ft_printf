#include "../ft_printf.h"

/*
**	Conversion i and d are call with appropriate function for flag 'h' conversion.
*/

void	ft_conversion_h_i_d(t_flags *fl, short int nb, const char *s)
{
	char	*conv;

	conv = ft_itoa_base(nb, 10);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'i');
	else
	{
		ft_flag_attrs(fl, 'i');
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

/*
**	Conversion i and d are call with appropriate function for flag 'hh' conversion.
*/

void	ft_conversion_hh_i_d(t_flags *fl, char nb, const char *s)
{
	char	*conv;

	conv = ft_itoa_base(nb, 10);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'i');
	else
	{
		ft_flag_attrs(fl, 'i');
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

/*
**	Conversion i and d are call with appropriate function for flag 'l' conversion.
*/

void	ft_conversion_l_i_d(t_flags *fl, long int nb, const char *s)
{
	char	*conv;

	conv = ft_ltoa_base(nb, 10);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'i');
	else
	{
		ft_flag_attrs(fl, 'i');
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

/*
**	Conversion i and d are call with appropriate function for flag 'll' conversion.
*/

void	ft_conversion_ll_i_d(t_flags *fl, long long int nb, const char *s)
{
	char	*conv;

	conv = ft_lltoa_base(nb, 10);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'i');
	else
	{
		ft_flag_attrs(fl, 'i');
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

/*
**	Conversion i and d are call with appropriate function when no flag is found.
*/

void	ft_conversion_i_d(t_flags *fl, int nb, const char *s)
{
	char	*conv;

	conv = ft_itoa_base(nb, 10);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'i');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'i');
	else
	{
		ft_flag_attrs(fl, 'i');
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}