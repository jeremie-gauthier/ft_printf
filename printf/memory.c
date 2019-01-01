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
	new->L = 0;
	new->dz = 0;
	new->f0 = 0;
	new->mo = 0;
	new->pl = 0;
	new->sp = 0;
	new->pad = 0;
	new->pr = 0;
	return (new);
}
