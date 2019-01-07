/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:08:12 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:08:13 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_regular_conv(t_flags *fl, va_list ap, char c, const char *s)
{
	if (c == 'i' || c == 'd')
		return (ft_conversion_i_d(fl, va_arg(ap, int), s));
	else if (c == 'b')
		return (ft_conversion_b(fl, va_arg(ap, unsigned int), s));
	else if (c == 'o')
		return (ft_conversion_o(fl, va_arg(ap, unsigned int), s));
	else if (c == 'u')
		return (ft_conversion_u(fl, va_arg(ap, unsigned int), s));
	else if (c == 'x')
		return (ft_conversion_xmin(fl, va_arg(ap, unsigned int), s));
	else if (c == 'X')
		return (ft_conversion_xmaj(fl, va_arg(ap, unsigned int), s));
	else if (c == 'f')
		return (ft_conversion_f(fl, va_arg(ap, double), s));
	return (0);
}

static int		ft_type_conv_extend(t_flags *fl, va_list ap, char c,
						const char *s)
{
	if (fl->ll)
	{
		if (c == 'i' || c == 'd')
			return (ft_conversion_ll_i_d(fl, va_arg(ap, long long int), s));
		else
			return (start_uns_long_long_conv(fl, va_arg(ap,
						unsigned long long int), c, s));
	}
	else if (fl->lm)
	{
		if (c == 'f')
			return (start_long_double_conv(fl, va_arg(ap, long double), s));
	}
	else
		return (ft_regular_conv(fl, ap, c, s));
	return (0);
}

/*
**	For flag conversion, call the good function with good type.
*/

int				ft_type_conv(t_flags *fl, va_list ap, char c, const char *s)
{
	if (fl->hh)
	{
		if (c == 'i' || c == 'd')
			return (ft_conversion_hh_i_d(fl, va_arg(ap, int), s));
		else
			return (start_uns_char_conv(fl, va_arg(ap, int), c, s));
	}
	else if (fl->h)
	{
		if (c == 'i' || c == 'd')
			return (ft_conversion_h_i_d(fl, va_arg(ap, int), s));
		else
			return (start_uns_short_conv(fl, va_arg(ap, int), c, s));
	}
	else if (fl->l)
	{
		if (c == 'i' || c == 'd')
			return (ft_conversion_l_i_d(fl, va_arg(ap, long int), s));
		else
			return (start_uns_long_conv(fl, va_arg(ap,
						unsigned long int), c, s));
	}
	else
		return (ft_type_conv_extend(fl, ap, c, s));
	return (0);
}
