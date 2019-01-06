#include "ft_printf.h"

int		ft_conversion_pc(t_flags *fl, const char *s)
{
	int		ret;

	ret = 1;
	if (fl->pad || fl->mo)
		ret = ft_pad_c(fl, '%', s);
	else
		ft_putchar('%');
	return (ret);
}