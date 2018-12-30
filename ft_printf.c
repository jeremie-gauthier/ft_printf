#include "ft_printf.h"

#include <stdio.h> //to debug

void	ft_putstr_unicode(char *str, size_t len)
{
	if (len){}
	while (*str)
	{
		if (!(*str & 0x80))
			write(1, &(*str), 1);
		else
			write(1, &(*str), 2);
		str++;
	}
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;

	va_start(ap, s);
	while (*s)
	{
		while (*s && *s != '%')
			ft_putchar(*s++);
		if (*s == '%' && *(s + 1) != '\0')
			s = ft_parser(s + 1, ap);
		else if (*(s + 1) == '\0')
			s++;
	}
	va_end(ap);
	return (1);
}

int	main(void)
{
	short	*ptr;
	// char	c = 'a';
	 short	nb = 30127;
	// unsigned long	ul =	2147483648;
	// unsigned long long	ull	= 3542698745;
	// long double	d = 0;
	char *str;
	int c = 0x00b6; // = \n
	int c = 
	write(1, &c, 4);
	ft_putchar('\n');
	str="ØøÜŷΩω";
	
	ft_putstr_unicode(str, ft_strlen(str));
	// char *c = "øi";
	// ft_putnbr(ft_strlen(c));
	// write(1, "ø", 2);

	ptr = &nb;
	// ft_printf("%s %--5c & %--10i & %05hd & %08ld & %lld & %#+.1Lf\n", "Bonjour", c, nb, nb, ul, ull, d);
	//    printf("%s %--5c & %--10i & %05hd & %08ld & %lld & %#+.01Lf\n", "Bonjour", c, nb, nb, ul, ull, d);
	ft_printf("\n%b", 8);//, c, nb, nb, ul, ull, d);
	printf("\n%i", 8);
	return (0);
}
