/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_i_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:06:18 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:06:20 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Conversion i and d are call with appropriate function for flag 'h'.
*/

int		ft_conversion_h_i_d(t_flags *fl, short int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_itoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'i');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i', conv);
		ft_putstr(conv);
	}
	if (conv)
		free(conv);
	return (ret);
}

/*
**	Conversion i and d are call with appropriate function for flag 'hh'.
*/

int		ft_conversion_hh_i_d(t_flags *fl, char nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_itoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'i');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i', conv);
		ft_putstr(conv);
	}
	if (conv)
		free(conv);
	return (ret);
}

/*
**	Conversion i and d are call with appropriate function for flag 'l'.
*/

int		ft_conversion_l_i_d(t_flags *fl, long int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_ltoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'i');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i', conv);
		ft_putstr(conv);
	}
	if (conv)
		free(conv);
	return (ret);
}

/*
**	Conversion i and d are call with appropriate function for flag 'll'.
*/

int		ft_conversion_ll_i_d(t_flags *fl, long long int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_lltoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'i');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i', conv);
		ft_putstr(conv);
	}
	if (conv)
		free(conv);
	return (ret);
}

/*
**	Conversion i and d are call with appropriate function when no flag is found.
*/

int		ft_conversion_i_d(t_flags *fl, int nb, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_itoa_base(nb, 10);
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxxb(fl, conv, s, 'i');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 'i', conv);
		ret += ft_flag_prec_diouxx(fl, conv, s, 'i');
	}
	else
	{
		ret += ft_flag_attrs(fl, 'i', conv);
		ft_putstr(conv);
	}
	if (conv)
		free(conv);
	return (ret);
}
