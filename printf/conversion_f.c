/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:06:08 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:11:24 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion_lmaj_f_extend(t_flags *fl, const char *s,
					const char *conv, unsigned int precis)
{
	int		ret;

	ret = 0;
	if (fl->pad || fl->mo)
		ret = ft_pad_f(fl, conv, s, precis);
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'f', conv);
		ret += ft_strlen(conv);
		ft_putstr_unicode(conv);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'f', conv);
		ft_putstr(conv);
	}
	return (ret);
}

int			ft_conversion_lmaj_f(t_flags *fl, long double nb, const char *s)
{
	unsigned int	precis;
	char			*conv;
	int				ret;

	conv = NULL;
	ret = 0;
	precis = 0;
	if (fl->pr == 0)
	{
		precis = 6;
		conv = ft_ldtoa(nb, precis);
		ret = ft_strlen(conv);
	}
	else if (fl->pr)
	{
		precis = ft_get_flag_value(s, '.');
		conv = ft_ldtoa(nb, precis);
		ret = ft_strlen(conv);
	}
	ret += ft_conversion_lmaj_f_extend(fl, s, conv, precis);
	if (conv)
		free(conv);
	return (ret);
}

static int	ft_conversion_f_extend(t_flags *fl, const char *s,
					const char *conv, unsigned int precis)
{
	int	ret;

	ret = 0;
	if (fl->pad || fl->mo)
		ret = ft_pad_f(fl, conv, s, precis);
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'f', conv);
		ret += ft_strlen(conv);
		ft_putstr_unicode(conv);
	}
	else
	{
		ret += ft_flag_attrs(fl, 'f', conv);
		ft_putstr(conv);
	}
	return (ret);
}

int			ft_conversion_f(t_flags *fl, double nb, const char *s)
{
	unsigned int	precis;
	char			*conv;
	int				ret;

	conv = NULL;
	ret = 0;
	precis = 0;
	if (fl->pr == 0)
	{
		precis = 6;
		conv = ft_dtoa(nb, precis);
		ret = ft_strlen(conv);
	}
	else if (fl->pr)
	{
		precis = ft_get_flag_value(s, '.');
		conv = ft_dtoa(nb, precis);
		ret = ft_strlen(conv);
	}
	ret += ft_conversion_f_extend(fl, s, conv, precis);
	if (conv)
		free(conv);
	return (ret);
}
