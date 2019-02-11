/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:21:37 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/05 17:21:38 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stdel(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		ft_memdel((void*)&tmp);
	}
	head = NULL;
}
