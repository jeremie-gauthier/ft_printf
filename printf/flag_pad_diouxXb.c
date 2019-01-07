/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pad_diouxxb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:15 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:07:16 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_pad_val(t_flags *fl, const char c, const char *s,
					const char *conv)
{
	int		pad_val;

	pad_val = (fl->mo) ? ft_get_flag_value(s, '-') : ft_get_flag_value(s, '1');
	if (c == 'i' || c == 'd')
	{
		if ((fl->sp || fl->pl) && conv && conv[0] != '-')
			pad_val--;
	}
	if ((c == 'o' || c == 'x' || c == 'X' || c == 'b') && fl->dz
				&& (ft_strlen(conv) != 1 || *conv != '0'))
		pad_val -= (c == 'x' || c == 'X' || c == 'b') ? 2 : 1;
	if (pad_val < 0)
		return (0);
	return (pad_val);
}

int			ft_put_zeroes(int pad_val, int len)
{
	int		tmp;

	tmp = len;
	while (len < pad_val)
	{
		ft_putchar('0');
		len++;
	}
	if (pad_val - tmp >= 0)
		return (pad_val - tmp);
	return (0);
}

int			ft_put_spaces(int pad_val, int len)
{
	int		tmp;

	tmp = pad_val;
	pad_val -= len;
	while (pad_val && pad_val > 0)
	{
		ft_putchar(' ');
		pad_val--;
	}
	if (tmp - len < 0)
		return (0);
	return (tmp - len);
}

int			ft_precision_format_int(const char *conv, int precis)
{
	int		len;

	len = ft_strlen(conv);
	while (len < precis)
	{
		ft_putchar('0');
		len++;
	}
	if (ft_strcmp(conv, "0") == 0)
	{
		if (precis > 0)
			ft_putstr_unicode(conv);
		else if (precis == 0)
			len = 0;
	}
	else
	{
		if (ft_strcmp(conv, "0") != 0)
			ft_putstr_unicode(conv);
	}
	return (len);
}

int			ft_pad_diouxxb(t_flags *fl, const char *conv, const char *s,
					const char c)
{
	if (fl->mo)
		return (ft_pad_diouxxb_right(fl, conv, s, c));
	else
		return (ft_pad_diouxxb_left(fl, conv, s, c));
	return (0);
}
