/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:21:54 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/05 17:21:55 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_stpush(t_stack **elem, t_stack *new)
{
	if (*elem)
	{
		new->next = *elem;
		*elem = new;
	}
	else
		*elem = new;
}
