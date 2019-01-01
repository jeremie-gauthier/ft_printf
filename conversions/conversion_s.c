#include "../ft_printf.h"

int		ft_conversion_s(t_flags *fl, char *str, const char *s)
{
	int		ret;

	ret = ft_strlen(str);
	if (fl->pad)
		ret = ft_flag_pad_left(fl, str, s, 'i');
	else
	{
		ret += ft_flag_attrs(fl, 's');
		if (str)
			ft_putstr_unicode(str);
	}
	return (ret);
}