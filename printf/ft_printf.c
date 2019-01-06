#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list	ap;
	int		ret;
	int		tmp;

	ret = 0;
	va_start(ap, s);
	while (*s)
	{
		while (*s && *s != '%')
		{
			ft_putchar(*s++);
			ret++;
		}
		if (*s == '%' && *(s + 1) != '\0')
		{
			s = ft_parser(s + 1, ap, &tmp);
			ret += tmp;
		}
		else if (*(s + 1) == '\0')
			s++;
	}
	va_end(ap);
	return (ret);
}