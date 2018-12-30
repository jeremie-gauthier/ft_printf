#include "../ft_printf.h"

void	ft_conversion_c(t_flags *fl, int nb, const char *s)
{
	nb = (unsigned char)nb;
	if (fl->mo)
		ft_flag_pad_right(fl, NULL, s, nb);
	else if (fl->pad)
		ft_flag_pad_left(fl, NULL, s, nb);
	else
		ft_putchar(nb);
}