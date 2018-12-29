#include "../ft_printf.h"

/*
**	Conversion x are call with appropriate function for flag 'h' conversion.
*/

void	ft_conversion_h_xmin(t_flags *fl, unsigned short int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_uitoa_base(nb, 16);
		str = ft_strlowcase(str);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion x are call with appropriate function for flag 'hh' conversion.
*/

void	ft_conversion_hh_xmin(t_flags *fl, unsigned char nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_uitoa_base(nb, 16);
		str = ft_strlowcase(str);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion x are call with appropriate function for flag 'l' conversion.
*/

void	ft_conversion_l_xmin(t_flags *fl, unsigned long int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_ultoa_base(nb, 16);
		str = ft_strlowcase(str);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion x are call with appropriate function for flag 'll' conversion.
*/

void	ft_conversion_ll_xmin(t_flags *fl, unsigned long long int nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_ulltoa_base(nb, 16);
		str = ft_strlowcase(str);
		ft_putstr(str);
		free(str);
	}
}

/*
**	Conversion x are call with appropriate function for no flag.
*/

void	ft_conversion_xmin(t_flags *fl, uintptr_t nb)
{
	char	*str;

	if (fl) //just to use it, to cancel error msgs
	{
		str = ft_uitoa_base(nb, 16);
		str = ft_strlowcase(str);
		ft_putstr(str);
		free(str);
	}
}