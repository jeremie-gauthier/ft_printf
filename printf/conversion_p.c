#include "ft_printf.h"

static char		*ft_ptr_to_str(uintptr_t nb)
{
	char	*conv;
	char	*tmp;

	tmp = ft_strlowcase(ft_uitoa_base(nb, 16));
	conv = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
	return (conv);
}

int		ft_conversion_p(t_flags *fl, void *p, const char *s)
{
	char	*conv;
	int		ret;

	conv = ft_ptr_to_str((uintptr_t)&(*p));
	ret = ft_strlen(conv);
	if (fl->mo)
		ret = ft_flag_pad_right(fl, conv, s, 'p');
	else if (fl->pad)
		ret = ft_flag_pad_left(fl, conv, s, 'p');
	else
		ft_putstr_unicode(conv);
	return (ret);
}