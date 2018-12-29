#include "ft_printf.h"

#include <stdio.h> //to debug

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
	short	*ptr;
	char	c = 'a';
	short	nb = 30127;
	unsigned long	ul =	2147483648;
	unsigned long long	ull	= 3542698745;
	long double	d = 1234.5678;

	ptr = &nb;
	ft_printf("\nBonjour %p & %hd & %hhd & %ld & %lld & %Lf\n", ptr, nb, c, ul, ull, d);
	printf("Bonjour %p & %0d & %hhd & %ld & %lld & %Lf\n", ptr, nb, c, ul, ull, d);
	return (0);
}
