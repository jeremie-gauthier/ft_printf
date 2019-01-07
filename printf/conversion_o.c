/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:06:24 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:06:25 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Conversion o are call with appropriate function for flag 'h' conversion.
*/

int		ft_conversion_h_o(t_flags *fl, unsigned short int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_uitoa_base(nb, 8);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'o');
	else if (fl->pr)
		ret += ft_flag_prec_diouxx(fl, conv, s, 'o');
	else
	{
		ret += ft_flag_attrs(fl, 'o', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion o are call with appropriate function for flag 'hh' conversion.
*/

int		ft_conversion_hh_o(t_flags *fl, unsigned char nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_uitoa_base(nb, 8);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'o');
	else if (fl->pr)
		ret += ft_flag_prec_diouxx(fl, conv, s, 'o');
	else
	{
		ret += ft_flag_attrs(fl, 'o', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion o are call with appropriate function for flag 'l' conversion.
*/

int		ft_conversion_l_o(t_flags *fl, unsigned long int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_ultoa_base(nb, 8);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'o');
	else if (fl->pr)
		ret += ft_flag_prec_diouxx(fl, conv, s, 'o');
	else
	{
		ret += ft_flag_attrs(fl, 'o', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion o are call with appropriate function for flag 'll' conversion.
*/

int		ft_conversion_ll_o(t_flags *fl, unsigned long long int nb,
				const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_ulltoa_base(nb, 8);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'o');
	else if (fl->pr)
		ret += ft_flag_prec_diouxx(fl, conv, s, 'o');
	else
	{
		ret += ft_flag_attrs(fl, 'o', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}

/*
**	Conversion o are call with appropriate function for no flag.
*/

int		ft_conversion_o(t_flags *fl, unsigned int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_uitoa_base(nb, 8);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'o');
	else if (fl->pr)
		ret = ft_flag_prec_diouxx(fl, conv, s, 'o');
	else
	{
		ret += ft_flag_attrs(fl, 'o', conv);
		ft_putstr(conv);
	}
	free(conv);
	return (ret);
}
