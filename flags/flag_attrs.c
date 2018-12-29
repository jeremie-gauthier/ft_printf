#include "../ft_printf.h"

/*
**	Returns the padding size in int.
*/

int		ft_flag_minus(t_flags *fl, char *s)
{
	int		padding;
	char	*spaces;

	padding = ft_atoi(s) - ft_strlen(s);
	if (padding < 0)
	{

	}
	else if (padding > 0)
	{
		while (padding-- >= 0)
			ft_putchar(' ');
	}
}

/*
**	Print a '+' before the data. (Overload the space flag)
*/

void	ft_flag_plus(t_flags *fl, char c)
{
	if (c == 'i' || c == 'd' || c == 'f')
		ft_putchar('+');
}

/*
**	Print a space before the data, if the flag '+' is not set.
*/

void	ft_flag_space(t_flags *fl, char c)
{
	if (fl->pl == 0)
	{
		if (c == 'i' || c == 'd' || c == 'f')
			ft_putchar(' ');
	}
}