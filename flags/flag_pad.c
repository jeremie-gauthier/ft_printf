#include "../ft_printf.h"

void	ft_flag_pad_right(t_flags *fl, const char *conv, const char *s, const char c)
{
	size_t	len;

	len = ft_strlen(s);
	len -= ((fl->sp | fl->pl) + fl->f0);
	if (fl->dz)
		len -= (c == 'x' || c == 'X') ? 2 : 1;
	if (conv)
		ft_putstr(conv);
	while (len--)
		ft_putchar(' ');
}

void	ft_flag_pad_left(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		padding;

	while (!ft_isdigit(*s))
		s++;
	padding = ft_atoi(s) - ((fl->sp | fl->pl) + fl->f0 + ft_strlen(conv));
	if (fl->dz)
		padding -= (c == 'x' || c == 'X') ? 2 : 1;
	while (padding--)
		ft_putchar(' ');
	if (conv)
		ft_putstr(conv);
}