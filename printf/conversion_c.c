#include "ft_printf.h"

int		ft_conversion_c(t_flags *fl, int nb, const char *s)
{
	int		ret;

	nb = (unsigned char)nb;
	ret = 1;
	if (fl->pad || fl->mo)
		ret = ft_pad_c(fl, nb, s);
	// else if (fl->pad)
	// 	ret = ft_flag_pad_left(fl, NULL, s, nb);
	else
		ft_putchar(nb);
	return (ret);
}