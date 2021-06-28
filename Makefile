# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 13:41:51 by yubae             #+#    #+#              #
#    Updated: 2021/06/28 14:10:31 by yubae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = node.c basiclist.c numlist.c ft_atolli.c push_swap.c main.c \
	   a_less3.c b_less3.c a_cmd.c b_cmd.c qs.c x2x.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
