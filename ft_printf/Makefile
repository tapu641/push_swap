NAME = libftprintf.a


SRCS = ft_printf.c ft_putunsigned.c ft_putptr.c \
		ft_putstr.c ft_putchar.c ft_puthex.c \
		ft_putnbr.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
