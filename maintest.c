#include "printf/ft_printf.h"

#include <stdio.h>

int	main(void)
{
	// short	*ptr;
	// char	c = 'a';
	//  short	nb = 30127;
	// unsigned long	ul =	2147483648;
	// unsigned long long	ull	= 3542698745;
	// long double	d = 7.0;
	// // char *str = "\U0001f921";
	// char *s = "\U0001F198";
int len = 0;
	char	*str;

	str = "blabla";
	// ptr = &nb;
	// ft_printf("%s %5c & %--10i & %05hd & %08ld & %lld & %#+.1Lf\n", s, c, nb, nb, ul, ull, d);
	//    printf("%s %5c & %--10i & %05hd & %08ld & %lld & %#+.01Lf\n", s, c, nb, nb, ul, ull, d);
	
	len = ft_printf("6chiffre 1 %+-5.1d chiffre 2 %4.d\n", -42, -42); // "% 012i", -291176810
	// ft_putchar('\n');
	ft_putnbr(len);
	ft_putendl("\n");
	   len = printf("6chiffre 1 %+-5.1d chiffre 2 %4.d\n", -42, -42);
	// ft_putchar('\n');
	ft_putnbr(len);
	ft_putchar('\n');
	return (0);
}
