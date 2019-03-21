# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergauth <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 19:46:18 by jergauth          #+#    #+#              #
#    Updated: 2019/03/21 12:55:38 by jergauth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

PTF_PATH	=	ft_printf

HDR		=	$(PTF_PATH)/ft_printf.h

LIB_PATH	=	libft

LIB		=	$(LIB_PATH)/libft.a

DIR_O	=	temporary

SOURCES	=	ft_printf.c			\
			memory.c			\
			parse_format.c		\
			parse_flag.c		\
			parse_color.c		\
			select_conversion.c	\
			conv_numeric.c		\
			conv_str.c			\
			conv_double.c		\
			conv_ptr.c			\
			format_flags.c		\
			format_regular_op.c	\
			format_comma.c		\
			format_precision.c	\
			format_char.c		\
			format_numeric.c	\
			ft_vprintf.c

SRCS	=	$(addprefix $(PTF_PATH)/,$(SOURCES))

OBJS	=	$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

CLEAN	=	clean

all:	$(NAME)

$(LIB):
		@make -C $(LIB_PATH)

$(NAME): $(OBJS) $(LIB) $(HDR) Makefile
		@cp $(LIB) ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "ft_printf	: libftprintf.a has been successfully created."

$(DIR_O)/%.o: $(PTF_PATH)/%.c
		@mkdir -p temporary
<<<<<<< HEAD
		@$(CC) $(CFLAGS) -I $(PTF_PATH) -o $@ -c $<
=======
		@$(CC) $(CFLAGS) -o $@ -c $<
>>>>>>> 6e996058b17827ce294020cc4e58e1f882a59ef8

clean:
		@$(RM) $(OBJS)
		@rm -rf $(DIR_O)
		@make clean -C $(LIB_PATH)
		@echo "ft_printf	: *.o files have been deleted."

fclean:	clean
		@$(RM) $(NAME) $(LIB)
		@echo "ft_printf	: libftprintf.a and libft.a has been deleted."

re:	fclean all

.PHONY:	all clean fclean re
