/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:22:40 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/05 17:22:41 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_destack(t_stack **current, size_t limit)
{
	t_stack	*tmp;
	size_t	i;

	i = 0;
	while (i < limit)
	{
		tmp = *current;
		*current = (*current)->next;
		ft_memdel((void*)&tmp);
		i++;
	}
}
