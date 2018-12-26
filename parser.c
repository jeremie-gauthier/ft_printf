#include "ft_printf.h"

/*
**	A special swap coded to swap bits from differents fields inside a bitfield.
*/

static void		swap_field(t_flags *fl, char field)
{
	if (field == 'h')
	{
		fl->h ^= fl->hh;
		fl->hh ^= fl->h;
		fl->h ^= fl->hh;
	}
	else if (field == 'l')
	{
		fl->l ^= fl->ll;
		fl->ll ^= fl->l;
		fl->l ^= fl->ll;
	}
}

/*
**	Ajout des flags dans la struct de bitfields `t_flags *fl`.
*/

static void		add_flag(const char c, t_flags *fl)
{
	if (c == 'h')
		(fl->h == 0) ? fl->h = 1 : swap_field(fl, 'h');
	else if (c == 'l')
		(fl->l == 0) ? fl->l = 1 : swap_field(fl, 'l');
	else if (c == 'L')
		fl->L = 1;
	else if (c == '#')
		fl->dz = 1;
	else if (c == '0')
		fl->f0 = 1;
	else if (c == '-')
		fl->mo = 1;
	else if (c == '+')
		fl->pl = 1;
	else if (c == ' ')
		fl->sp = 1;
}

/*
**	Checks whether the char `c` is a conversion specifier or not.
*/

static int		not_a_conversion_specifier(const char c)
{
	return (!(c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
		c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'f'));
}

const char		*ft_parser(const char *s, va_list ap)
{
	t_flags		*fl;

	fl = init_flags();
	while (*s && not_a_conversion_specifier(*s))
		add_flag(*s++, fl);
	if (*s == 'i' || *s == 'd')
		ft_conversion_i_d(fl, va_arg(ap, int));
	if (*s == 'o')
		ft_conversion_o(fl, va_arg(ap, unsigned int));
	free(fl);
	return (s + 1);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		ft_parser(argv[1]);
// 	}
// 	return (0);
// }
