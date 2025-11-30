NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

MLX_DIR     = ./minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a

PRINTF_DIR  = ./ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

LDFLAGS     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L$(PRINTF_DIR) -lftprintf

SRCS        = main.c key_press.c get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c load_image.c \
              so_long_utils.c flood_fill.c all_validation.c read_map.c\
              free_game.c

OBJS        = $(SRCS:.c=.o)

all: $(MLX) $(PRINTF) $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
