#include "../ft_printf.h"

void	ft_conversion_p(t_flags *fl, void *p)
{
	if (fl) //just to use it, to cancel error msgs
	{
		ft_putstr("0x");
		ft_conversion_xmin(fl, (uintptr_t)&(*p));
	}
}