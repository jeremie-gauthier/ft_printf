#include "../ft_printf.h"

static char		*ft_ptr_to_str(uintptr_t nb)
{
	char	*conv;
	char	*tmp;

	tmp = ft_strlowcase(ft_uitoa_base(nb, 16));
	conv = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
	return (conv);
}

void	ft_conversion_p(t_flags *fl, void *p, const char *s)
{
	char	*conv;

	conv = ft_ptr_to_str((uintptr_t)&(*p));
	if (fl->mo)
		ft_flag_pad_right(fl, conv, s, 'p');
	else if (fl->pad)
		ft_flag_pad_left(fl, conv, s, 'p');
	else
		ft_putstr_unicode(conv);
}