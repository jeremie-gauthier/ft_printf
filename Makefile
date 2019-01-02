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

NAME	=	libftprintf.a

PTF_PATH	=	printf

HDR		=	$(PTF_PATH)/ft_printf.h

LIB_PATH	=	libft

LIB		=	$(LIB_PATH)/libft.a

DIR_O	=	temporary

SOURCES	=	ft_printf.c		memory.c	parser.c	\
			conversion_i_d.c	\
			conversion_b.c		\
			conversion_o.c		\
			conversion_u.c		\
			conversion_xmin.c	\
			conversion_xmaj.c	\
			conversion_c.c	\
			conversion_s.c	\
			conversion_p.c	\
			conversion_pc.c	\
			conversion_f.c	\
			type_conv.c		\
			start_conv.c	\
			flag_attrs.c	\
			flag_pad.c		\
			flag_prec.c

SRCS	=	$(addprefix $(PTF_PATH)/,$(SOURCES))

OBJS	=	$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

CLEAN	=	clean

all		:	$(NAME)

$(LIB)	:
			@make -C $(LIB_PATH)

$(NAME)	:	$(OBJS) $(LIB) Makefile
			@#@make -C $(LIB_PATH)
			@cp $(LIB) ./$(NAME)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "libftprintf.a has been successfully created."

$(DIR_O)/%.o: $(PTF_PATH)/%.c
		@mkdir -p temporary
		@$(CC) $(CFLAGS) -I $(HDR) -o $@ -c $<

clean	:
			@$(RM) $(OBJS)
			@rm -rf $(DIR_O)
			@make clean -C $(LIB_PATH)
			@echo "All .o files have been deleted."

fclean	:	clean
			@$(RM) $(NAME) $(LIB)
			@echo "libftprintf.a and libft.a has been deleted."

re		:	fclean all

.PHONY:	all clean fclean re
