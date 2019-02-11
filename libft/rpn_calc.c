/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:27:53 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/06 11:27:56 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	operations(int a, int b, char c, int *ret)
{
	if (c == '+')
		*ret = a + b;
	else if (c == '-')
		*ret = a - b;
	else if (c == '*')
		*ret = a * b;
	else if (c == '/')
	{
		if (b == 0)
			return (0);
		*ret = a / b;
	}
	else if (c == '%')
	{
		if (b == 0)
			return (0);
		*ret = a % b;
	}
	return (1);
}

static int	check(char *str)
{
	if (*str == ' ')
		return (0);
	while (*str)
	{
		if (*str != '+' && *str != '-' && *str != '*' && *str != '/'
					&& *str != '%' && *str != ' ' && (*str < '0' || *str > '9'))
			return (0);
		str++;
	}
	return (1);
}

void	manage_stack(t_stack **elem, int nb)
{
	t_stack	*operand;

	operand = ft_stnew(nb);
	ft_stpush(elem, operand);
}



int		parsing(char *str, int *ret)
{
	t_stack	*current;

	current = NULL;
	if (check(str) == 0)
	{
		printf("Error\n");
		return (0);
	}
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if ((*str >= '0' && *str <= '9') || (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9'))
		{
			manage_stack(&current, atoi(str));
			if (*str == '+' || *str == '-')
				str++;
			while (*str && *str >= '0' && *str <= '9')
				str++;
		}
		else if (ft_instr(*str, "+-*/%"))
		{
			if (current && current->next)
			{
				if ((operations(current->next->nb, current->nb, *str, ret)) == 0)
				{
					printf("Error\n");
					ft_stdel(&current);
					return (0);
				}
				ft_destack(&current, 2);
				manage_stack(&current, *ret);
				str++;
			}
			else
			{
				printf("Error\n");
				ft_stdel(&current);
				return (0);
			}
		}
		else
			str++;
	}
	if (current == NULL || current->next != NULL)
		printf("Error\n");
	else
		printf("%i\n", *ret);
	ft_stdel(&current);
	return (1);
}


//----------------------------//
int		main(int argc, char **argv)
{
	int		ret;

	if (argc == 2)
	{
		parsing(argv[1], &ret);
	}
	else
		printf("Error\n");
	return (0);
}
