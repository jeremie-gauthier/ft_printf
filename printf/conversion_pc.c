/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:06:33 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:06:35 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion_pc(t_flags *fl, const char *s)
{
	int		ret;

	ret = 1;
	if (fl->pad || fl->mo)
		ret = ft_pad_c(fl, '%', s);
	else
		ft_putchar('%');
	return (ret);
}
