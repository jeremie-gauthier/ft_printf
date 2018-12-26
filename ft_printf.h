#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

//Rajouter la precision ?
typedef struct	s_flags
{
	unsigned short	hh	: 1;
	unsigned short	h	: 1;
	unsigned short	l	: 1;
	unsigned short	ll	: 1;
	unsigned short	L	: 1;
	unsigned short	dz	: 1;
	unsigned short	f0	: 1;
	unsigned short	mo	: 1;
	unsigned short	pl	: 1;
	unsigned short	sp	: 1;
}				t_flags;

t_flags			*init_flags(void);
void			*init_funptr(void);
const char		*ft_parser(const char *s, va_list ap);
void			ft_conversion_i_d(t_flags *fl, int nb);
void			ft_conversion_o(t_flags *fl, unsigned int nb);

#endif
