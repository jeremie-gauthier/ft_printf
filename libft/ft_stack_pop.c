/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:05:25 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/13 11:05:26 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Remove the 'nb' firsts top elem of the stack and free them.
*/

void	ft_stack_pop(t_stack **head, int nb)
{
	t_stack	*tmp;
	int		i;

	if (*head)
	{
		i = 0;
		while (i < nb)
		{
			tmp = *head;
			*head = (*head)->next;
			tmp->nb = 0;
			ft_memdel((void*)&tmp);
			i++;
		}
	}
}
