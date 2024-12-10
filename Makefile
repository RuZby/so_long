SRCS = so_long.c event.c texture.c check_map.c utils.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MLX = ./mlx_linux/libmlx.a

LIBFT = ./libft/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(MLX):
	make -C mlx_linux all

$(LIBFT):
	make -C libft all

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

clean:
	make -sC mlx_linux clean
	make -sC libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re