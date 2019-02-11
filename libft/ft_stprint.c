/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:21:48 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/05 17:21:49 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_stprint(t_stack *current)
{
	while (current)
	{
		ft_putnbr(current->nb);
		ft_putchar('\n');
		current = current->next;
	}
	ft_putendl("(null)");
}
