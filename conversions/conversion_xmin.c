#include "../ft_printf.h"

/*
**	Conversion x are call with appropriate function for flag 'h' conversion.
*/

void	ft_conversion_h_xmin(t_flags *fl, unsigned short int nb, const char *s)
{
	char	*conv;

	conv = ft_strlowcase(ft_uitoa_base(nb, 16));
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'x');
	else
		ft_putstr(conv);
	free(conv);
}

/*
**	Conversion x are call with appropriate function for flag 'hh' conversion.
*/

void	ft_conversion_hh_xmin(t_flags *fl, unsigned char nb, const char *s)
{
	char	*conv;

	conv = ft_strlowcase(ft_uitoa_base(nb, 16));
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'x');
	else
		ft_putstr(conv);
	free(conv);
}

/*
**	Conversion x are call with appropriate function for flag 'l' conversion.
*/

void	ft_conversion_l_xmin(t_flags *fl, unsigned long int nb, const char *s)
{
	char	*conv;

	conv = ft_strlowcase(ft_ultoa_base(nb, 16));
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'x');
	else
		ft_putstr(conv);
	free(conv);
}

/*
**	Conversion x are call with appropriate function for flag 'll' conversion.
*/

void	ft_conversion_ll_xmin(t_flags *fl, unsigned long long int nb, const char *s)
{
	char	*conv;

	conv = ft_strlowcase(ft_ulltoa_base(nb, 16));
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'x');
	else
		ft_putstr(conv);
	free(conv);
}

/*
**	Conversion x are call with appropriate function for no flag.
*/

void	ft_conversion_xmin(t_flags *fl, uintptr_t nb, const char *s)
{
	char	*conv;

	conv = ft_strlowcase(ft_uitoa_base(nb, 16));
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'x');
	else
		ft_putstr(conv);
	free(conv);
}