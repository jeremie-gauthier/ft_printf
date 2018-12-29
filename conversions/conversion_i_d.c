#include "../ft_printf.h"

/*
**	Conversion i and d are call with appropriate function for flag 'h' conversion.
*/

void	ft_conversion_h_i_d(t_flags *fl, short int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_itoa_base(nb, 10);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion i and d are call with appropriate function for flag 'hh' conversion.
*/

void	ft_conversion_hh_i_d(t_flags *fl, char nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_itoa_base(nb, 10);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion i and d are call with appropriate function for flag 'l' conversion.
*/

void	ft_conversion_l_i_d(t_flags *fl, long int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_ltoa_base(nb, 10);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion i and d are call with appropriate function for flag 'll' conversion.
*/

void	ft_conversion_ll_i_d(t_flags *fl, long long int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_lltoa_base(nb, 10);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion i and d are call with appropriate function when no flag is found.
*/

void	ft_conversion_i_d(t_flags *fl, int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_itoa_base(nb, 10);
		ft_putstr(str);
		free(str);
	}
}