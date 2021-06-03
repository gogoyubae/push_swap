# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 13:41:51 by yubae             #+#    #+#              #
#    Updated: 2021/06/03 14:54:08 by yubae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

SRCS = basiclist.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) $(OBJS) -c -o $@ $^

$(NAME): $(OBJS)
	make -C ./libft
	cp Libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)


clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

