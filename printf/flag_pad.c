#include "ft_printf.h"

static int		deduct_flags(t_flags *fl, const char c, const char *s, const char flag_search)
{
	int		pad_value;

	pad_value = ft_get_flag_value(s, flag_search);
	if (c == 'i' || c == 'd')
		pad_value -= (fl->sp | fl->pl);
	if ((c == 'o' || c == 'x' || c == 'X' || c == 'b') && fl->dz)
		pad_value -= (c == 'x' || c == 'X' || c == 'b') ? 2 : 1;
	if (pad_value < 0)
		return (0);
	return (pad_value);
}

static int		pad_value_str(t_flags *fl, const char *conv, const char *s, int pad_value)
{
	int		prec;
	int		ret;
	char	*dup;
	int		len;

	ret = 0;
	prec = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	len = ft_strlen(conv) - prec;
	len = (len < 0) ? 0 : len;
	if (fl->mo == 0)
	{
		while (len++ < pad_value)
			ft_putchar(' ');
	}
	ret += ft_flag_attrs(fl, 's', conv);
	if (ft_strncmp(conv, "", 1) && fl->mo == 0)
		return (pad_value + ret);
	prec = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	if (fl->pr && conv)
	{
		dup = ft_strndup(conv, prec);
		ft_putstr_unicode(dup);
		ft_strdel(&dup);
	}
	else
		ft_putstr_unicode(conv);
	if (fl->mo == 1)
	{
		if (fl->pr)
		{
			while (prec++ < pad_value)
				ft_putchar(' ');
		}
		else
		{
			while (len++ < pad_value)
				ft_putchar(' ');
		}
	}
	return (pad_value + ret);
}

// static int		deduct_len_pr(t_flags *fl, const char *conv, const char *s)
// {
// 	int		len;
// 	int		prec;

// 	len = (conv == NULL) ? 1 : ft_strlen(conv);
// 	prec = 0;
// 	if (fl->pr)
// 		prec = ft_get_flag_value(s, '.');
// 	if (prec < len)
// 		return (prec);
// 	return (len);
// }

int		ft_flag_pad_right(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		pad_value;
	int		len;
	int		prec;
	int		ret;

	pad_value = deduct_flags(fl, c, s, '-');
	len = (conv == NULL) ? 1 : ft_strlen(conv);
	prec = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	ft_putstr("\npad_value : ");
	ft_putnbr(pad_value);
	ft_putchar('\n');
	ft_putstr("\nlen(conv) : ");
	ft_putnbr(len);
	ft_putchar('\n');
	ft_putstr("\nprec : ");
	ft_putnbr(prec);
	ft_putchar('\n');
	prec = (len > prec) ? len : prec;
	ret = ft_flag_attrs(fl, c, conv);
	if (pad_value > prec)
	{
		if (c != 's')
		{
			while (len++ < prec)
				ft_putchar('0');
		}
		if (conv)
		{
			if (c == 's')
				return (pad_value_str(fl, conv, s, pad_value));
			(ft_strcmp(conv, "0") == 0) ? 0 : ft_putstr_unicode(conv);
		}
		else
			ft_putchar(c);
		while (prec++ < pad_value)
			ft_putchar(' ');
		return (pad_value + ret);
	}
	else if (prec > len)
	{
		while (len++ < prec)
			ft_putchar('0');
		(conv != NULL) ? ft_putstr_unicode(conv) : ft_putchar(c);
		return (prec + ret);
	}
	else
	{
		if (c == 's')
			return (pad_value_str(fl, conv, s, pad_value));
		//	ft_flag_prec_s((char*)conv, s);
		else
			ft_flag_prec_diouxX((char*)conv, s);	
	}
	return (len + ret);
}

int		ft_flag_pad_left(t_flags *fl, const char *conv, const char *s, const char c)
{
	int		pad_value;
	int		len;
	int		prec;
	int		ret;

	pad_value = deduct_flags(fl, c, s, '1');
	len = (conv == NULL) ? 1 : ft_strlen(conv);
	// if (ft_strncmp(conv, "", 1) == 0)
	// 	len = 1;
	prec = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
	ft_putstr("\npad_value : ");
	ft_putnbr(pad_value);
	ft_putchar('\n');
	ft_putstr("\nlen(conv) : ");
	ft_putnbr(len);
	ft_putchar('\n');
	ft_putstr("\nprec : ");
	ft_putnbr(prec);
	ft_putchar('\n');
	prec = (len > prec) ? len : prec;
	ret = 0;
	if (pad_value > prec)
	{
		if (fl->f0 == 1 && fl->pr == 0)
		{
			if (*conv == '-')
			{
				ft_putchar(*conv++);
				(fl->pl) ? pad_value++ : 0;
				fl->pl = 0;
			}
			ret = ft_flag_attrs(fl, c, conv);
			while (prec++ < pad_value)
				ft_putchar('0');
		}
		else if (fl->f0 == 0 || fl->pr == 1)
		{
			if (fl->pr || c == 's')
				return (pad_value_str(fl, conv, s, pad_value));
			else
			{
				if (conv && *conv == '-')
				{
					ft_putchar(*conv++);
					(fl->pl) ? pad_value++ : 0;
					fl->pl = 0;
				}
				while (prec++ < pad_value)
					(fl->f0) ? ft_putchar('0') :ft_putchar(' ');
				ret = ft_flag_attrs(fl, c, conv);
			}
		}
		prec = (fl->pr == 1) ? ft_get_flag_value(s, '.') : 0;
		prec = (len > prec) ? len : prec;
		while (c != 's' && len++ < prec)
			ft_putchar('0');
		if (conv)
		{
			if (ft_strcmp(conv, "\0") == 0)
				ft_putchar(' ');
			// else if (ft_strcmp(conv, "0") != 0 && c != 'd' && c != 'i')
			if (fl->pr)
				ft_flag_prec_diouxX((char*)conv, s);
			else
				ft_putstr_unicode(conv);
		}
		else if (conv == NULL)
			ft_putchar(c);
		else
			(ft_strcmp(conv, "\0") == 0) ? ft_putchar(' ') : ft_putchar(c);			
		return (pad_value + ret);
	}
	else if (prec > len)
	{
		ret = ft_flag_attrs(fl, c, conv);
		while (len++ < prec)
			ft_putchar('0');
		(conv != NULL) ? ft_putstr_unicode(conv) : ft_putchar(c);
		return (prec + ret);
	}
	else
	{
		ret = ft_flag_attrs(fl, c, conv);
		if (c == 's')
			ft_flag_prec_s((char*)conv, s);
		else
			ft_flag_prec_diouxX((char*)conv, s);
	}
	return (len + ret);
}