#include "../ft_printf.h"

/*
**	Conversion o are call with appropriate function for flag 'h' conversion.
*/

void	ft_conversion_h_o(t_flags *fl, unsigned short int nb, const char *s)
{
	char	*conv;

	conv = ft_uitoa_base(nb, 8);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'o');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'o');
	else
	{
		ft_flag_attrs(fl, 'o', conv);
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

/*
**	Conversion o are call with appropriate function for flag 'hh' conversion.
*/

void	ft_conversion_hh_o(t_flags *fl, unsigned char nb, const char *s)
{
	char	*conv;

	conv = ft_uitoa_base(nb, 8);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'o');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'o');
	else
	{
		ft_flag_attrs(fl, 'o', conv);
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

/*
**	Conversion o are call with appropriate function for flag 'l' conversion.
*/

void	ft_conversion_l_o(t_flags *fl, unsigned long int nb, const char *s)
{
	char	*conv;

	conv = ft_ultoa_base(nb, 8);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'o');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'o');
	else
	{
		ft_flag_attrs(fl, 'o', conv);
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

/*
**	Conversion o are call with appropriate function for flag 'll' conversion.
*/

void	ft_conversion_ll_o(t_flags *fl, unsigned long long int nb, const char *s)
{
	char	*conv;

	conv = ft_ulltoa_base(nb, 8);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'o');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'o');
	else
	{
		ft_flag_attrs(fl, 'o', conv);
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}

/*
**	Conversion o are call with appropriate function for no flag.
*/

void	ft_conversion_o(t_flags *fl, unsigned int nb, const char *s)
{
	char	*conv;

	conv = ft_uitoa_base(nb, 8);
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'o');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'o');
	else
	{
		ft_flag_attrs(fl, 'o', conv);
		if (conv)
			ft_putstr(conv);
	}
	free(conv);
}