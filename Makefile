NAME = so_long

SRC_FILES = main.c window_display.c map_parsing.c fct_utils.c fct_utils2.c game_tracking.c\
	gnl/get_next_line.c gnl/gnl_utils.c \
	ftprint/ft_printf.c ftprint/ft_print_ptr.c ftprint/ft_putchar.c \
	ftprint/ft_puthex.c ftprint/ft_putnbr.c ftprint/ft_putstr.c \
	ftprint/ft_put_unsigned.c\
	


SRC = $(addprefix src/, $(SRC_FILES))
OBJS = $(SRC:.c=.o)

MLX = ./minilibx-linux/libmlx_Linux.a
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext -lbsd

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
