/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:05:58 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:06:00 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion_c(t_flags *fl, int nb, const char *s)
{
	int		ret;

	nb = (unsigned char)nb;
	ret = 1;
	if (fl->pad || fl->mo)
		ret = ft_pad_c(fl, nb, s);
	else
		ft_putchar(nb);
	return (ret);
}
