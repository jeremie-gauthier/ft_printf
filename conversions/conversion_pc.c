#include "../ft_printf.h"

void	ft_conversion_pc(t_flags *fl, const char *s)
{
	if (fl->mo)
		ft_flag_pad_right(fl, "%", s, '%');
	else if (fl->pad)
		ft_flag_pad_left(fl, "%", s, '%');
	else
		ft_putchar('%');
}