/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pad_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:30 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:07:31 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_padding(t_flags *fl, int pad_val, int len, int precis)
{
	int		tmp;

	len = (fl->pr && len < precis) ? precis : len;
	tmp = len;
	while (len < pad_val)
	{
		(fl->f0) ? ft_putchar('0') : ft_putchar(' ');
		len++;
	}
	return (len - tmp);
}

int			ft_pad_f(t_flags *fl, const char *conv, const char *s, int precis)
{
	int		pad_val;
	int		len;
	int		ret;

	pad_val = (fl->mo) ? ft_get_flag_value(s, '-') : ft_get_flag_value(s, '1');
	len = (fl->pr && precis == 0) ? 0 : ft_strlen(conv);
	ret = 0;
	if (fl->mo)
	{
		ret += ft_flag_attrs(fl, 'f', conv);
		ret += ft_strlen(conv);
		ft_putstr_unicode(conv);
		ret += ft_put_padding(fl, pad_val, len, precis);
	}
	else
	{
		ret += ft_put_padding(fl, pad_val, len, precis);
		ret += ft_flag_attrs(fl, 'f', conv);
		ret += ft_strlen(conv);
		ft_putstr_unicode(conv);
	}
	return (ret);
}
