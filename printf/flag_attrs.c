#include "ft_printf.h"

/*
**	Print a '+' before the data. (Overload the space flag)
*/

static int		ft_flag_plus(const char c)
{
	if (c == 'i' || c == 'd' || c == 'f')
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}

/*
**	Print a space before the data, if the flag '+' is not set.
*/

static int		ft_flag_space(t_flags *fl, const char c)
{
	if (fl->pl == 0)
	{
		if (c == 'i' || c == 'd' || c == 'f')
		{
			ft_putchar(' ');
			return (1);
		}
	}
	return (0);
}

/*
**	Write a prefix before the data.
**	octal	= '0'
**	hexa	= 'x' or 'X'
*/

static int		ft_flag_dz(const char c)
{
	if (c == 'b')
	{
		ft_putstr("0b");
		return (2);
	}
	else if (c == 'o')
	{
		ft_putchar('0');
		return (1);
	}
	else if (c == 'x')
	{
		ft_putstr("0x");
		return (2);
	}
	else if (c == 'X')
	{
		ft_putstr("0X");
		return (2);
	}
	return (0);
}

int				ft_flag_attrs(t_flags *fl, const char c, const char *conv)
{
	int	ret;

	ret = 0;
	// ft_putstr("\nLEN depart: ");
	// ft_putnbr(ret);
	// ft_putchar('\n');
	if (conv && fl->pl && conv[0] != '-')
		ret += ft_flag_plus(c);
	else if (conv && fl->sp && conv[0] != '-')
		ret += ft_flag_space(fl, c);
	if (conv && fl->dz)
		ret += ft_flag_dz(c);
	// ft_putstr("\nLEN flag #: ");
	// ft_putnbr(ret);
	// ft_putchar('\n');

	// if (fl->pr)
	// {
	// 	if (c == 's')
	// 		ret += ft_flag_prec_s((char*)conv, s);
	// 	else
	// 		ret += ft_flag_prec_diouxX((char*)conv, s);
	// }
	// ft_putstr("\nLEN flag pr: ");
	// ft_putnbr(ret);
	// ft_putchar('\n');

	return (ret);
}