/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:08:02 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:08:03 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (!(c == '#' || c == '0' || c == '-' || c == '+' || c == ' '
						|| c == '.'));
}

static int		ft_parser_extend(t_flags *fl, const char *s, va_list ap,
						const char *sptr)
{
	int	ret;

	ret = 0;
	if (*s == 'd' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'x'
						|| *s == 'X' || *s == 'f' || *s == 'b')
		ret = ft_type_conv(fl, ap, *s, sptr);
	else if (*s == 'c')
		ret = ft_conversion_c(fl, va_arg(ap, int), sptr);
	else if (*s == 's')
		ret = ft_conversion_s(fl, va_arg(ap, char*), sptr);
	else if (*s == 'p')
		ret = ft_conversion_p(fl, va_arg(ap, void*), sptr);
	else if (*s == '%')
		ret = ft_conversion_pc(fl, sptr);
	else
	{
		ret += 1;
		ft_putchar(*s);
	}
	return (ret);
}

/*
**	Parse flags.
*/

const char		*ft_parser(const char *s, va_list ap, int *ret)
{
	t_flags		*fl;
	const char	*sptr;

	*ret = 0;
	sptr = s;
	fl = init_flags();
	while (*s && (!not_an_attrs_flag(*s) || ft_isdigit(*s)))
	{
		add_flag(*s++, fl);
		if (fl->mo || fl->pr || fl->pad || fl->f0)
			while (*s && ft_isdigit(*s))
				s++;
	}
	while (*s && !not_a_conv_flag(*s))
		add_flag(*s++, fl);
	*ret += ft_parser_extend(fl, s, ap, sptr);
	free(fl);
	return (s + 1);
}
