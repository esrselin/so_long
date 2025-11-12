NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
MLX_DIR     = ./minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a

LDFLAGS     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS        = main.c key_press.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c load_image.c
OBJS        = $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re