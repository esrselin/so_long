NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_puthex.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_unbr.c ft_printf.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)
$(NAME): $(OBJS)
	ar rcs -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
