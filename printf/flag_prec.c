#include "ft_printf.h"

int		ft_flag_prec_diouxX(char *conv, const char *s)
{
	unsigned int	precis;
	size_t			len;

	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(conv);
	if (precis > len)
	{
		while (len < precis)
		{
			ft_putchar('0');
			len++;
		}
		ft_putstr(conv);
		return (precis);
	}
	else if (precis <= len)
	{
		(ft_strcmp(conv, "0") == 0) ? 0 : ft_putstr_unicode(conv);
		len--;
	}
	return (len);
}

int		ft_flag_prec_s(char *str, const char *s)
{
	unsigned int	precis;
	unsigned int	i;
	size_t			len;

	precis = ft_get_flag_value(s, '.');
	len = ft_strlen(str);
	if (precis < len)
	{
		i = 0;
		while (i < precis)
			ft_putchar(str[i++]);
		// ft_putnbr(len);
		// str[precis] = '\0';
		// ft_putstr(str);
		return (precis);
	}
	else if (precis >= len)
		ft_putstr(str);
	return (len);
}
