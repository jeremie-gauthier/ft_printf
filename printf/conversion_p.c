#include "ft_printf.h"

static char		*ft_ptr_to_str(unsigned long nb)
{
	char	*conv;
	char	*tmp;

	tmp = ft_strlowcase(ft_ultoa_base(nb, 16));
	conv = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
	return (conv);
}

int		ft_conversion_p(t_flags *fl, void *p, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_ptr_to_str((unsigned long)&(*p));
	ret = ft_strlen(conv);
	if (fl->pad || fl->mo)
		ret = ft_pad_diouxXb(fl, conv, s, 'p');
	else
		ft_putstr_unicode(conv);
	return (ret);
}