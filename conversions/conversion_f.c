#include "../ft_printf.h"

void	ft_conversion_f(t_flags *fl, double nb)
{
	
	if (fl->pr < 0) // to del
		fl->pr = 6;
	ft_putdouble(nb, fl->pr);
}
