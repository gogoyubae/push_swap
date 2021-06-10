# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 16:21:50 by yubae             #+#    #+#              #
#    Updated: 2021/03/06 17:52:11 by yubae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_check.c ft_write.c\
	   ft_putdi.c ft_putux.c ft_putp.c ft_putc.c ft_puts.c\

OBJ = $(SRC:.c=.o)

AR = ar rcs
RM = rm -rf
INC_LINK = -I. -I./libft

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC_LINK) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	make -C ./libft
	cp Libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean :
	make -C ./libft clean
	$(RM) $(OBJ)

fclean : clean
	make -C ./libft fclean
	$(RM) $(NAME) 

re : fclean all

.PHONY: all clean fclean re libft
