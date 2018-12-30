# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergauth <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 19:46:18 by jergauth          #+#    #+#              #
#    Updated: 2018/12/26 19:46:20 by jergauth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf #mettre en .a

SRCS	=	ft_printf.c		memory.c	parser.c	\
			conversions/conversion_i_d.c	\
			conversions/conversion_o.c		\
			conversions/conversion_u.c		\
			conversions/conversion_xmin.c	\
			conversions/conversion_xmaj.c	\
			conversions/conversion_c.c	\
			conversions/conversion_s.c	\
			conversions/conversion_p.c	\
			conversions/conversion_pc.c	\
			conversions/conversion_f.c	\
			conversions/type_conv.c		\
			conversions/start_conv.c	\
			flags/flag_attrs.c	\
			flags/flag_pad.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

HDR		=	ft_printf.h

LIB_PATH	=	libft/

LIB		=	$(LIB_PATH)/libft.a

RM		=	rm -f

CLEAN	=	clean

all		:	$(NAME)

$(LIB)	:
			@make -C $(LIB_PATH)

$(NAME)	:	$(OBJS) $(HDR) $(LIB)
			@$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(SRCS) -I $(HDR)
			@echo "ft_printf.a has been successfully created."

clean	:
			@$(RM) $(OBJS)
			@make clean -C $(LIB_PATH)
			@echo "All .o files have been deleted."

fclean	:	clean
			@$(RM) $(NAME) $(LIB)
			@echo "ft_printf.a and libft.a has been deleted."

re		:	fclean all
