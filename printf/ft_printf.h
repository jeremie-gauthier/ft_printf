#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	unsigned short	hh	: 1;
	unsigned short	h	: 1;
	unsigned short	l	: 1;
	unsigned short	ll	: 1;
	unsigned short	L	: 1;
	unsigned short	dz	: 1;
	unsigned short	f0	: 1;
	unsigned short	mo	: 1;
	unsigned short	pl	: 1;
	unsigned short	sp	: 1;
	unsigned short	pad	: 1;
	unsigned short	pr	: 1;
}				t_flags;

int				ft_printf(const char *s, ...);

t_flags			*init_flags(void);
void			*init_funptr(void);
const char		*ft_parser(const char *s, va_list ap, int *ret);

int				ft_type_conv(t_flags *fl, va_list ap, char c, const char *s);
int				start_uns_char_conv(t_flags *fl, unsigned char data, char c, const char *s);
int				start_uns_short_conv(t_flags *fl, unsigned short int data, char c, const char *s);
int				start_uns_long_conv(t_flags *fl, unsigned long int data, char c, const char *s);
int				start_uns_long_long_conv(t_flags *fl, unsigned long long int data, char c, const char *s);
int				start_long_double_conv(t_flags *fl, long double data, const char *s);

int				ft_conversion_i_d(t_flags *fl, int nb, const char *s);
int				ft_conversion_h_i_d(t_flags *fl, short int nb, const char *s);
int				ft_conversion_hh_i_d(t_flags *fl, char nb, const char *s);
int				ft_conversion_l_i_d(t_flags *fl, long int nb, const char *s);
int				ft_conversion_ll_i_d(t_flags *fl, long long int nb, const char *s);

int				ft_conversion_b(t_flags *fl, unsigned int nb, const char *s);
int				ft_conversion_h_b(t_flags *fl, unsigned short int nb, const char *s);
int				ft_conversion_hh_b(t_flags *fl, unsigned char nb, const char *s);
int				ft_conversion_l_b(t_flags *fl, unsigned long int nb, const char *s);
int				ft_conversion_ll_b(t_flags *fl, unsigned long long int nb, const char *s);

int				ft_conversion_o(t_flags *fl, unsigned int nb, const char *s);
int				ft_conversion_h_o(t_flags *fl, unsigned short int nb, const char *s);
int				ft_conversion_hh_o(t_flags *fl, unsigned char nb, const char *s);
int				ft_conversion_l_o(t_flags *fl, unsigned long int nb, const char *s);
int				ft_conversion_ll_o(t_flags *fl, unsigned long long int nb, const char *s);

int				ft_conversion_u(t_flags *fl, unsigned int nb, const char *s);
int				ft_conversion_h_u(t_flags *fl, unsigned short int nb, const char *s);
int				ft_conversion_hh_u(t_flags *fl, unsigned char nb, const char *s);
int				ft_conversion_l_u(t_flags *fl, unsigned long int nb, const char *s);
int				ft_conversion_ll_u(t_flags *fl, unsigned long long int nb, const char *s);

int				ft_conversion_xmin(t_flags *fl, uintptr_t nb, const char *s);
int				ft_conversion_h_xmin(t_flags *fl, unsigned short int nb, const char *s);
int				ft_conversion_hh_xmin(t_flags *fl, unsigned char nb, const char *s);
int				ft_conversion_l_xmin(t_flags *fl, unsigned long int nb, const char *s);
int				ft_conversion_ll_xmin(t_flags *fl, unsigned long long int nb, const char *s);

int				ft_conversion_xmaj(t_flags *fl, unsigned int nb, const char *s);
int				ft_conversion_h_xmaj(t_flags *fl, unsigned short int nb, const char *s);
int				ft_conversion_hh_xmaj(t_flags *fl, unsigned char nb, const char *s);
int				ft_conversion_l_xmaj(t_flags *fl, unsigned long int nb, const char *s);
int				ft_conversion_ll_xmaj(t_flags *fl, unsigned long long int nb, const char *s);

int				ft_conversion_f(t_flags *fl, double nb, const char *s);
int				ft_conversion_L_f(t_flags *fl, long double nb, const char *s);

int				ft_conversion_c(t_flags *fl, int nb, const char *s);
int				ft_conversion_s(t_flags *fl, char *str, const char *s);
int				ft_conversion_p(t_flags *fl, void *p, const char *s);
int				ft_conversion_pc(t_flags *fl, const char *s);

int				ft_pad_str(t_flags *fl, const char *str, const char *s);


int				ft_get_flag_value(const char *s, const char c);
int				ft_flag_attrs(t_flags *fl, char c, const char *conv);
int				ft_flag_pad_right(t_flags *fl, const char *conv, const char *s, const char c);
int				ft_flag_pad_left(t_flags *fl, const char *conv, const char *s, const char c);
int				ft_flag_prec_diouxX(t_flags *fl, char *conv, const char *s);
int				ft_flag_prec_s(char *str, const char *s);

#endif
