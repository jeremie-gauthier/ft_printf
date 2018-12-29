#include "../ft_printf.h"

void	ft_conversion_c(t_flags *fl, int nb)
{
	if (fl) //just to use it, to cancel error msgs
	{
	nb = (unsigned char)nb;
	write(1, &nb, 1);
		// ft_putchar((unsigned char)nb);
	}
}