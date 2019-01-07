/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pad_diouxxb_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:24 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:07:25 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_do_precision(t_flags *fl, const char *conv, const char c,
				int precis)
{
	int	ret;

	ret = 0;
	if (conv && *conv == '-')
	{
		ft_putchar(*conv++);
		ret++;
		fl->pl = 0;
	}
	ret += ft_flag_attrs(fl, c, conv);
	ret += ft_precision_format_int((char*)conv, precis);
	return (ret);
}

static int	ft_no_precision(t_flags *fl, const char *conv, const char c,
				int pad_val)
{
	int	ret;

	ret = 0;
	ret += ft_flag_attrs(fl, c, conv);
	ret += ft_strlen(conv);
	if (conv && *conv == '-')
	{
		ft_putchar(*conv++);
		(fl->pl) ? pad_val++ : 0;
		(fl->pl) ? ret-- : 0;
		fl->pl = 0;
	}
	ft_putstr_unicode(conv);
	return (ret);
}

int			ft_pad_diouxxb_right(t_flags *fl, const char *conv, const char *s,
				const char c)
{
	int		pad_val;
	int		len;
	int		precis;
	int		ret;

	pad_val = ft_get_flag_value(s, '-');
	len = ft_strlen(conv);
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	fl->f0 = 0;
	ret = 0;
	if (fl->pr)
		ret += ft_do_precision(fl, conv, c, precis);
	else
		ret += ft_no_precision(fl, conv, c, pad_val);
	pad_val -= ret;
	if (pad_val < 0)
		pad_val = 0;
	ret += ft_put_spaces(pad_val, 0);
	return (ret);
}
