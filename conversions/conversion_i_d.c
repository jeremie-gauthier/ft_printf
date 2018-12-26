#include "../ft_printf.h"

void	ft_conversion_i_d(t_flags *fl, int nb)
{
	char	*str;

	if (fl)
	{
		str = ft_itoa_base(nb, 10);
		ft_putstr(str);
		free(str);
	}
}