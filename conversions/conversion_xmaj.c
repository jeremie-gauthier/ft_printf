#include "../ft_printf.h"

/*
**	Conversion X are call with appropriate function for flag 'h' conversion.
*/

void	ft_conversion_h_xmaj(t_flags *fl, unsigned short int nb, const char *s)
{
	char	*conv;

	conv = ft_uitoa_base(nb, 16);
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'X');
	else
		ft_putstr(conv);
	free(conv);
}

/*
**	Conversion X are call with appropriate function for flag 'hh' conversion.
*/

void	ft_conversion_hh_xmaj(t_flags *fl, unsigned char nb, const char *s)
{
	char	*conv;

	conv = ft_uitoa_base(nb, 16);
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'X');
	else
		ft_putstr(conv);
	free(conv);
}

/*
**	Conversion X are call with appropriate function for flag 'l' conversion.
*/

void	ft_conversion_l_xmaj(t_flags *fl, unsigned long int nb, const char *s)
{
	char	*conv;

	conv = ft_ultoa_base(nb, 16);
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'X');
	else
		ft_putstr(conv);
	free(conv);
}

/*
**	Conversion X are call with appropriate function for flag 'll' conversion.
*/

void	ft_conversion_ll_xmaj(t_flags *fl, unsigned long long int nb, const char *s)
{
	char	*conv;

	conv = ft_ulltoa_base(nb, 16);
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'X');
	else
		ft_putstr(conv);
	free(conv);
}

/*
**	Conversion X are call with appropriate function for no flag.
*/

void	ft_conversion_xmaj(t_flags *fl, unsigned int nb, const char *s)
{
	char	*conv;

	conv = ft_uitoa_base(nb, 16);
	if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'X');
	else
		ft_putstr(conv);
	free(conv);
}