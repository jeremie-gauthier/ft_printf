/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:21:42 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/05 17:21:44 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_stnew(int nb)
{
	t_stack	*new;

	if (!(new = (t_stack*)malloc(sizeof(*new))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}
