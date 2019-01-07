/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pad_diouxxb_left.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:20 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:07:21 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	deal_with_neg(t_flags *fl, const char **conv, int pad_val)
{
	int	ret;

	ret = 0;
	if (conv && *conv && **conv == '-')
	{
		ft_putchar(**conv);
		*conv += 1;
		(fl->pl) ? pad_val++ : 0;
		fl->pl = 0;
		ret = 1;
	}
	return (ret);
}

static int	ft_put_spaces_pr(int pad_val, int precis, int len, const char *conv)
{
	int		tmp;

	if (ft_strcmp(conv, "0") == 0 && precis == 0)
	{
		tmp = 0;
		while (precis < pad_val)
		{
			ft_putchar(' ');
			precis++;
		}
	}
	else
	{
		precis = (precis > len) ? precis : len;
		tmp = precis;
		if (pad_val < precis)
			return (0);
		while (precis < pad_val)
		{
			ft_putchar(' ');
			precis++;
		}
	}
	return (pad_val - tmp);
}

static int	pad_pr(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		pad_val;
	int		len;
	int		precis;
	int		ret;
	int		sign;

	sign = (*conv == '-') ? 1 : 0;
	pad_val = get_pad_val(fl, c, s, conv);
	len = ft_strlen(conv);
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	ret = 0;
	if (pad_val > precis + sign)
		ret += ft_put_spaces_pr(pad_val, precis + sign, len, conv);
	ret += ft_flag_attrs(fl, c, conv);
	ret += deal_with_neg(fl, &conv, pad_val);
	ret += ft_precision_format_int((char*)conv, precis);
	return (ret);
}

static int	pad_no_pr(t_flags *fl, const char *conv, const char *s,
				const char c)
{
	int		pad_val;
	int		len;
	int		precis;
	int		ret;
	int		prefix;

	prefix = (fl->dz == 1) ? 1 : 0;
	pad_val = get_pad_val(fl, c, s, conv);
	len = ft_strlen(conv);
	precis = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	ret = 0;
	if (fl->f0 == 0)
	{
		ret += ft_put_spaces(pad_val, len) + deal_with_neg(fl, &conv, pad_val);
		ret += ft_flag_attrs(fl, c, conv);
		(prefix == 0 || ft_strcmp(conv, "0")) ? ft_putstr_unicode(conv) : 0;
	}
	else if (fl->f0 == 1)
	{
		ret += deal_with_neg(fl, &conv, pad_val) + ft_flag_attrs(fl, c, conv);
		ret += ft_put_zeroes(pad_val, len);
		(prefix == 0 || ft_strcmp(conv, "0")) ? ft_putstr_unicode(conv) : 0;
	}
	ret += ft_strlen(conv);
	return ((c == 'o' && ft_strcmp(conv, "0") == 0) ? ret - prefix : ret);
	// return (ret);
}

int			ft_pad_diouxxb_left(t_flags *fl, const char *conv, const char *s,
				const char c)
{
	if (fl->pr)
	{
		fl->f0 = 0;
		return (pad_pr(fl, conv, s, c));
	}
	return (pad_no_pr(fl, conv, s, c));
}
