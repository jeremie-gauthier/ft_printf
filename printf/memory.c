/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:57 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:07:58 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Malloc and set each field of a bitfield struct `t_flags` to 0.
*/

t_flags		*init_flags(void)
{
	t_flags		*new;

	if (!(new = (t_flags*)malloc(sizeof(*new))))
		return (NULL);
	new->hh = 0;
	new->h = 0;
	new->l = 0;
	new->ll = 0;
	new->lm = 0;
	new->dz = 0;
	new->f0 = 0;
	new->mo = 0;
	new->pl = 0;
	new->sp = 0;
	new->pad = 0;
	new->pr = 0;
	return (new);
}

/*
**	A special swap coded to swap bits from differents fields inside a bitfield.
*/

static void	swap_field(t_flags *fl, char field)
{
	if (field == 'h')
	{
		fl->h ^= fl->hh;
		fl->hh ^= fl->h;
		fl->h ^= fl->hh;
	}
	else if (field == 'l')
	{
		fl->l ^= fl->ll;
		fl->ll ^= fl->l;
		fl->l ^= fl->ll;
	}
}

/*
**	Ajout des flags dans la struct de bitfields `t_flags *fl`.
*/

void		add_flag(const char c, t_flags *fl)
{
	if (c == 'h')
		(fl->h == 0) ? fl->h = 1 : swap_field(fl, 'h');
	else if (c == 'l')
		(fl->l == 0) ? fl->l = 1 : swap_field(fl, 'l');
	else if (c == 'L')
		fl->lm = 1;
	else if (c == '#')
		fl->dz = 1;
	else if (c == '0')
	{
		fl->f0 = 1;
		fl->pad = 1;
	}
	else if (c == '-')
		fl->mo = 1;
	else if (c == '+')
		fl->pl = 1;
	else if (c == ' ')
		fl->sp = 1;
	else if (ft_isdigit(c))
		fl->pad = 1;
	else if (c == '.')
		fl->pr = 1;
}

/*
**	Parse the string to get the value of a flag.
*/

static int	ft_get_flag_value_extend(const char *s, const char c)
{
	while (*s && *s != c)
		s++;
	while (*s && *s == c)
		s++;
	if (c == '-')
	{
		while (*s && !ft_isdigit(*s) && *s != '.')
			s++;
		if (*s && *s == '.')
			return (0);
	}
	return (ft_abs(ft_atoi(s)));
}

/*
**	Parse the string to get the value of a flag.
*/

int			ft_get_flag_value(const char *s, const char c)
{
	if (c == '1')
	{
		while (*s == '0')
			s++;
		while (*s && !ft_isdigit(*s))
			s++;
		if (ft_abs(ft_atoi(s)) != 0)
			return (ft_abs(ft_atoi(s)));
		while (*s && !ft_isdigit(*s))
			s++;
		return (ft_abs(ft_atoi(s + 1)));
	}
	return (ft_get_flag_value_extend(s, c));
}
