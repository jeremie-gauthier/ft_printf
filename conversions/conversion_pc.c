#include "../ft_printf.h"

int		ft_conversion_pc(t_flags *fl, const char *s)
{
	int		ret;

	ret = 1;
	if (fl->mo)
		ret = ft_flag_pad_right(fl, "%", s, '%');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, "%", s, '%');
	else
		ft_putchar('%');
	return (ret);
}