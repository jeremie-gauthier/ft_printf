#include "../ft_printf.h"

/*
**	Call the good function when a 'hh' flag is found.
*/

void		start_uns_char_conv(t_flags *fl, unsigned char data, char c)
{
	if (c == 'o')
		ft_conversion_hh_o(fl, data);
	else if (c == 'u')
		ft_conversion_hh_u(fl, data);
	else if (c == 'x')
		ft_conversion_hh_xmin(fl, data);
	else if (c == 'X')
		ft_conversion_hh_xmaj(fl, data);
}

/*
**	Call the good function when a 'h' flag is found.
*/

void		start_uns_short_conv(t_flags *fl, unsigned short int data, char c)
{
	if (c == 'o')
		ft_conversion_h_o(fl, data);
	else if (c == 'u')
		ft_conversion_h_u(fl, data);
	else if (c == 'x')
		ft_conversion_h_xmin(fl, data);
	else if (c == 'X')
		ft_conversion_h_xmaj(fl, data);
}

/*
**	Call the good function when a 'l' flag is found.
*/

void		start_uns_long_conv(t_flags *fl, unsigned long int data, char c)
{
	if (c == 'o')
		ft_conversion_l_o(fl, data);
	else if (c == 'u')
		ft_conversion_l_u(fl, data);
	else if (c == 'x')
		ft_conversion_l_xmin(fl, data);
	else if (c == 'X')
		ft_conversion_l_xmaj(fl, data);
}

/*
**	Call the good function when a 'll' flag is found.
*/

void		start_uns_long_long_conv(t_flags *fl, unsigned long long int data, char c)
{
	if (c == 'o')
		ft_conversion_ll_o(fl, data);
	else if (c == 'u')
		ft_conversion_ll_u(fl, data);
	else if (c == 'x')
		ft_conversion_ll_xmin(fl, data);
	else if (c == 'X')
		ft_conversion_ll_xmaj(fl, data);
}

/*
**	Call the good function when a 'L' flag is found.
*/

void		start_long_double_conv(t_flags *fl, long double data)
{
	ft_conversion_f(fl, data);
}