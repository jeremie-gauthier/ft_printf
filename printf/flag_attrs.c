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
	if (conv && fl->pl && conv[0] != '-')
	{
		ret += ft_flag_plus(c);
		fl->pl = 0;
	}
	else if (conv && fl->sp)
	{
		ret += (conv && *conv == '-' && (c == 'd' || c == 'i')) ? 0 : ft_flag_space(fl, c);
		fl->sp = 0;
	}
	//	if (c != 'o' && ft_strcmp(conv, "0") != 0)
/*# 0087 (int)
  ft_printf("%#6o", 2500);
  1. (    5) --> 4704<--
  2. (    6) --> 04704<--

# 0088 (int)
  ft_printf("%-#6o", 2500);
  1. (    6) -->4704  <--
  2. (    6) -->04704 <--

# 0095 (int)
  ft_printf("@moulitest: %#.o %#.0o", 0, 0);
  1. (   13) -->@moulitest:  <--
  2. (   15) -->@moulitest: 0 0<--
*/
	if (conv && fl->dz)
	{
		// if (ft_strlen(conv) != 1 || *conv != '0')
		// {
			// ft_putstr("ici");
		if (ft_strcmp(conv, "0") != 0)
			ret += ft_flag_dz(c);
		else
		{
			if (c == 'o')
				ret += ft_flag_dz(c);
		}
		// }
		fl->dz = 0;
	}
	return (ret);
}