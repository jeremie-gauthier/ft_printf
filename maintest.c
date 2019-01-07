#include "printf/ft_printf.h"

#include <stdio.h>

int	main(void)
{
	char	*ptr;
	char	c = 'a';
	//  short	nb = 30127;
	// unsigned long	ul =	2147483648;
	// unsigned long long	ull	= 3542698745;
	// long double	d = 7.0;
	// // char *str = "\U0001f921";
	// char *s = "\U0001F198";
int len = 0;
	char	*str;
	char	*ret;
	char	*p_all_01;

	ret = "Coucou";
	p_all_01 = "56";
	str = "@moulitest: %#.o %#.0o\n", 0, 0;
	
	char	*str2;
	str2 = "test %-7M %007d%-10.2ls!!\n";
	ptr = &c;
	// ft_printf("%s %5c & %--10i & %05hd & %08ld & %lld & %#+.1Lf\n", s, c, nb, nb, ul, ull, d);
	//    printf("%s %5c & %--10i & %05hd & %08ld & %lld & %#+.01Lf\n", s, c, nb, nb, ul, ull, d);
	/*# 0040 (int)
  ft_printf("%#x", 0);
  1. (    3) -->0x0<--
  2. (    1) -->0<--

# 0046 (int)
  ft_printf("@moulitest: %#.x %#.0x", 0, 0);
  1. (   17) -->@moulitest: 0x 0x<--
  2. (   13) -->@moulitest:  <--*/

	//"@moulitest: %#.o %#.0o", 0, 0 [95] Moi: pas de 0 affiche || Lui: 0 affiches
	//"@moulitest: %.o %.0o", 0, 0    \n
	len = ft_printf("test %25p!!", ptr);
	ft_putchar('\n');
	ft_putnbr(len);
	ft_putendl("\n");
	   len = printf("test %25p!!", ptr);
	ft_putchar('\n');
	ft_putnbr(len);
	ft_putchar('\n');
	return (0);
}
