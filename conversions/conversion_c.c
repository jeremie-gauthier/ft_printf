#include "../ft_printf.h"

void	ft_conversion_c(t_flags *fl, int nb, const char *s)
{
	nb = (unsigned char)nb;
	write(1, &nb, 1);
	if (fl->pad)
		ft_flag_pad_left(fl, NULL, s, 'c');
}