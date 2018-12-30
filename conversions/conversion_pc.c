#include "../ft_printf.h"

void	ft_conversion_pc(t_flags *fl, const char *s)
{
	ft_putchar('%');
	if (fl->pad)
		ft_flag_pad_left(fl, NULL, s, 'c');
}