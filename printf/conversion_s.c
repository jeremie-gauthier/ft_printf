#include "ft_printf.h"

int		ft_conversion_s(t_flags *fl, char *str, const char *s)
{
	int		ret;

	ret = ft_strlen(str);
	if (fl->pad)
		ret = ft_flag_pad_left(fl, str, s, 's');
	else if (fl->pr)
	{
		ret = ft_flag_attrs(fl, 's');
		ret += ft_flag_prec_s(str, s);
	}
	else
		ft_putstr_unicode(str);
	return (ret);
}