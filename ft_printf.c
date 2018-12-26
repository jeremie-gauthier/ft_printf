#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list	ap;

	va_start(ap, s);
	while (*s)
	{
		while (*s && *s != '%')
			ft_putchar(*s++);
		if (*s == '%')
			s = ft_parser(s + 1, ap);
	}
	va_end(ap);
	return (1);
}

int	main(void)
{

	ft_printf("Bonjour @%o &%i\n", 8, 16);

	return (0);
}
