# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/20 21:46:43 by rnagai            #+#    #+#              #
#    Updated: 2026/06/26 21:29:59 by rnagai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I ft_printf
LIBFT	=	ft_printf/libftprintf.a
SRCS	=	main.c \
			bench.c \
			complex_sort.c \
			compress.c \
			five_sort.c \
			medium_sort.c \
			node_operations.c \
			parse.c \
			push.c \
			rev_rotate_ops.c \
			rotate_ops.c \
			simple_sort.c \
			stack.c \
			swap.c \
			three_sort.c \
			util.c
OBJS	=	$(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ft_printf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re	