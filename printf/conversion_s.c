/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:06:38 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:06:39 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion_s(t_flags *fl, char *str, const char *s)
{
	int		ret;

	if (str == NULL)
		str = ft_strdup("(null)");
	ret = ft_strlen(str);
	if (fl->pad || fl->mo)
		ret = ft_pad_str(fl, str, s);
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 's', str);
		ret += ft_flag_prec_s(str, s);
	}
	else
		ft_putstr_unicode(str);
	if (ft_strcmp(str, "(null)") == 0)
		ft_strdel(&str);
	return (ret);
}
