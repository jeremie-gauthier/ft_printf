#include "ft_printf.h"

int		ft_get_flag_value(const char *s, const char c)
{
	while (*s && *s != c)
		s++;
	return (ft_abs(ft_atoi(s + 1)));
}

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
	{
		fl->f0 = 1;
		fl->pad = 1;
	}
	else if (c == '-')
		fl->mo = 1;
	else if (c == '+')
		fl->pl = 1;
	else if (c == ' ')
		fl->sp = 1;
	else if (ft_isdigit(c))
		fl->pad = 1;
	else if (c == '.')
		fl->pr = 1;
}

/*
**	Checks whether the char `c` is a conversion specifier or not.
*/

// static int		not_a_conversion_specifier(const char c)
// {
// 	return (!(c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
// 		c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'f'));
// }

/*
**	The char c is not a conversion flag.
*/

static int		not_a_conv_flag(const char c)
{
	return (!(c == 'h' || c == 'l' || c == 'L'));
}

/*
**	The char c is not a flag character.
*/

static int		not_an_attrs_flag(const char c)
{
	return (!(c == '#' || c == '0' || c == '-' || c == '+' || c == ' ' || c == '.'));
}

/*
**	Parse flags.
*/

const char		*ft_parser(const char *s, va_list ap, int *ret)
{
	t_flags		*fl;
	const char	*sptr;

	sptr = s;
	fl = init_flags();
	//On cherche en premier tous les caracteres d'attributs.
	while (*s && (!not_an_attrs_flag(*s) || ft_isdigit(*s)))
	{
		add_flag(*s++, fl);
		if (fl->mo || fl->pr || fl->pad || fl->f0)
			while (*s && ft_isdigit(*s))
				s++;
	}
	// Puis tous les flags concernant la conversion.
	while (*s && !not_a_conv_flag(*s))
		add_flag(*s++, fl);
	// Et on convertit :D
	if (*s == 'd' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'x' || *s == 'X' || *s == 'f' || *s == 'b')
		*ret = ft_type_conv(fl, ap, *s, sptr);
	else if (*s == 'c')
		*ret = ft_conversion_c(fl, va_arg(ap, int), sptr);
	else if (*s == 's')
		*ret = ft_conversion_s(fl, va_arg(ap, char*), sptr);
	else if (*s == 'p')
		*ret = ft_conversion_p(fl, va_arg(ap, void*), sptr);
	else if (*s == '%')
		*ret = ft_conversion_pc(fl, sptr);
	free(fl);
	return (s + 1);
}
