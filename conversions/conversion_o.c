#include "../ft_printf.h"

void	ft_conversion_o(t_flags *fl, unsigned int nb)
{
	char	*str;

	if (fl)
	{
		str = ft_uitoa_base(nb, 8);
		ft_putstr(str);
		free(str);
	}
}