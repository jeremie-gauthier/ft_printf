#include "../ft_printf.h"

/*
**	Call the good function when a 'hh' flag is found.
*/

void		start_uns_char_conv(t_flags *fl, unsigned char data, char c, const char *s)
{
	if (c == 'b')
		ft_conversion_hh_b(fl, data, s);
	else if (c == 'o')
		ft_conversion_hh_o(fl, data, s);
	else if (c == 'u')
		ft_conversion_hh_u(fl, data, s);
	else if (c == 'x')
		ft_conversion_hh_xmin(fl, data, s);
	else if (c == 'X')
		ft_conversion_hh_xmaj(fl, data, s);
}

/*
**	Call the good function when a 'h' flag is found.
*/

void		start_uns_short_conv(t_flags *fl, unsigned short int data, char c, const char *s)
{
	if (c == 'b')
		ft_conversion_h_b(fl, data, s);
	else if (c == 'o')
		ft_conversion_h_o(fl, data, s);
	else if (c == 'u')
		ft_conversion_h_u(fl, data, s);
	else if (c == 'x')
		ft_conversion_h_xmin(fl, data, s);
	else if (c == 'X')
		ft_conversion_h_xmaj(fl, data, s);
}

/*
**	Call the good function when a 'l' flag is found.
*/

void		start_uns_long_conv(t_flags *fl, unsigned long int data, char c, const char *s)
{
	if (c == 'b')
		ft_conversion_l_b(fl, data, s);
	else if (c == 'o')
		ft_conversion_l_o(fl, data, s);
	else if (c == 'u')
		ft_conversion_l_u(fl, data, s);
	else if (c == 'x')
		ft_conversion_l_xmin(fl, data, s);
	else if (c == 'X')
		ft_conversion_l_xmaj(fl, data, s);
}

/*
**	Call the good function when a 'll' flag is found.
*/

void		start_uns_long_long_conv(t_flags *fl, unsigned long long int data, char c, const char *s)
{
	if (c == 'b')
		ft_conversion_ll_b(fl, data, s);
	else if (c == 'o')
		ft_conversion_ll_o(fl, data, s);
	else if (c == 'u')
		ft_conversion_ll_u(fl, data, s);
	else if (c == 'x')
		ft_conversion_ll_xmin(fl, data, s);
	else if (c == 'X')
		ft_conversion_ll_xmaj(fl, data, s);
}

/*
**	Call the good function when a 'L' flag is found.
*/

void		start_long_double_conv(t_flags *fl, long double data, const char *s)
{
	ft_conversion_L_f(fl, data, s);
}