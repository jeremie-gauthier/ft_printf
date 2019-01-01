#include "ft_printf.h"

int		ft_flag_prec_diouxX(char *conv, const char *s)
{
	unsigned int	precis;
	size_t			len;
	size_t			len_save;

	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(conv);
	if (precis > len)
	{
		len_save = len;
		while (len < precis)
		{
			ft_putchar('0');
			len++;
		}
		return (precis - len_save);
	}
	return (len);
}

int		ft_flag_prec_s(char *str, const char *s)
{
	unsigned int	precis;
	size_t			len;

	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(str);
	if (precis < len)
	{
		str[precis] = '\0';
		return (precis);
	}
	return (len);
}
