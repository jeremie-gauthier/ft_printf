#include "../ft_printf.h"

void	ft_conversion_s(t_flags *fl, char *str, const char *s)
{
	if (fl->pad)
		ft_flag_pad_left(fl, str, s, 'i');
	else
		ft_putstr(str);
}