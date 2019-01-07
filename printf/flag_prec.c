/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:39 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:07:39 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag_prec_extend(t_flags *fl, char *conv, int precis,
					const char c)
{
	int	len;

	len = -1;
	if (ft_strcmp(conv, "0") == 0 && precis == 0 && c != 'o')
	{
		if (fl->pad)
			ft_putchar(' ');
	}
	else if (ft_strlen(conv) != 1 || ft_strcmp(conv, "0") != 0)
	{
		len++;
		ft_putstr_unicode(conv);
	}
	else if (ft_strcmp(conv, "0") == 0 && precis > 0)
	{
		len++;
		ft_putstr_unicode(conv);
	}
	return (len);
}

int			ft_flag_prec_diouxx(t_flags *fl, char *conv, const char *s,
					const char c)
{
	int		precis;
	int		sign;
	int		len;
	int		ret;

	sign = (conv && *conv == '-') ? 1 : 0;
	if (conv && *conv == '-')
		ft_putchar(*conv++);
	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(conv);
	ret = ft_flag_attrs(fl, c, conv);
	precis -= ret;
	if (precis > len)
	{
		while (len++ < precis)
			ft_putchar('0');
		ft_putstr(conv);
		return (precis + ret + sign);
	}
	else if (precis <= len)
		len += ft_flag_prec_extend(fl, conv, precis, c);
	return (len + sign + ret);
}

int			ft_flag_prec_s(char *str, const char *s)
{
	unsigned int	precis;
	size_t			len;
	char			*dup;

	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(str);
	if (precis < len)
	{
		dup = ft_strndup(str, precis);
		ft_putstr_unicode(dup);
		ft_strdel(&dup);
		return (precis);
	}
	else if (precis >= len)
		ft_putstr(str);
	return (len);
}
