#include "../ft_printf.h"

/*
**	Print a '+' before the data. (Overload the space flag)
*/

static void		ft_flag_plus(const char c)
{
	if (c == 'i' || c == 'd' || c == 'f')
		ft_putchar('+');
}

/*
**	Print a space before the data, if the flag '+' is not set.
*/

static void		ft_flag_space(t_flags *fl, const char c)
{
	if (fl->pl == 0)
	{
		if (c == 'i' || c == 'd' || c == 'f')
			ft_putchar(' ');
	}
}

/*
**	Write a prefix before the data.
**	octal	= '0'
**	hexa	= 'x' or 'X'
*/

static void		ft_flag_dz(const char c)
{
	if (c == 'b')
		ft_putstr("0b");
	else if (c == 'o')
		ft_putchar('0');
	else if (c == 'x')
		ft_putstr("0x");
	else if (c == 'X')
		ft_putstr("0X");
}

void			ft_flag_attrs(t_flags *fl, const char c)
{
	if (fl->pl)
		ft_flag_plus(c);
	else if (fl->sp)
		ft_flag_space(fl, c);
	if (fl->dz)
		ft_flag_dz(c);
}