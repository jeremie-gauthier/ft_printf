#include "ft_printf.h"

#include <stdio.h> //to debug

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

// int	main(void)
// {
// 	// short	*ptr;
// 	char	c = 'a';
// 	 short	nb = 30127;
// 	unsigned long	ul =	2147483648;
// 	unsigned long long	ull	= 3542698745;
// 	long double	d = 7.0;
// 	// char *str = "\U0001f921";
// 	char *s = "\U0001F198";
// int len = 0;
// 	// ptr = &nb;
// 	// ft_printf("%s %5c & %--10i & %05hd & %08ld & %lld & %#+.1Lf\n", s, c, nb, nb, ul, ull, d);
// 	//    printf("%s %5c & %--10i & %05hd & %08ld & %lld & %#+.01Lf\n", s, c, nb, nb, ul, ull, d);
// 	len = ft_printf("%s %5c & %--10i & %05hd & %08ld & %lld & %#+.8Lf\n",  s, c, nb, nb, ul, ull, d / 2.0);
// 	ft_putnbr(len);
// 	ft_putchar('\n');
// 	   len = printf("%s %5c & %--10i & %05hd & %08ld & %lld & %#+.8Lf\n",  s, c, nb, nb, ul, ull, d / 2.0);
// 	ft_putnbr(len);
// 	ft_putchar('\n');
// 	return (0);
// }
