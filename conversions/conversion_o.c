#include "../ft_printf.h"

/*
**	Conversion o are call with appropriate function for flag 'h' conversion.
*/

void	ft_conversion_h_o(t_flags *fl, unsigned short int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_uitoa_base(nb, 8);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion o are call with appropriate function for flag 'hh' conversion.
*/

void	ft_conversion_hh_o(t_flags *fl, unsigned char nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_uitoa_base(nb, 8);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion o are call with appropriate function for flag 'l' conversion.
*/

void	ft_conversion_l_o(t_flags *fl, unsigned long int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_ultoa_base(nb, 8);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion o are call with appropriate function for flag 'll' conversion.
*/

void	ft_conversion_ll_o(t_flags *fl, unsigned long long int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_ulltoa_base(nb, 8);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion o are call with appropriate function for no flag.
*/

void	ft_conversion_o(t_flags *fl, unsigned int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_uitoa_base(nb, 8);
		ft_putstr(str);
		free(str);
	}
}