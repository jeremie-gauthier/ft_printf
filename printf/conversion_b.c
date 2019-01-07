/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:05:40 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:09:57 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Conversion b are call with appropriate function for flag 'h' conversion.
*/

int		ft_conversion_h_b(t_flags *fl, unsigned short int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_uitoa_base(nb, 2);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'b');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'b', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'b');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'b', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion b are call with appropriate function for flag 'hh' conversion.
*/

int		ft_conversion_hh_b(t_flags *fl, unsigned char nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_uitoa_base(nb, 2);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'b');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'b', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'b');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'b', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion b are call with appropriate function for flag 'l' conversion.
*/

int		ft_conversion_l_b(t_flags *fl, unsigned long int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_ultoa_base(nb, 2);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'b');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'b', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'b');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'b', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion b are call with appropriate function for flag 'll' conversion.
*/

int		ft_conversion_ll_b(t_flags *fl, unsigned long long int nb,
			const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_ulltoa_base(nb, 2);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'b');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'b', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'b');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'b', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion b are call with appropriate function for no flag.
*/

int		ft_conversion_b(t_flags *fl, unsigned int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_uitoa_base(nb, 2);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'b');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'b', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'b');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'b', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}
