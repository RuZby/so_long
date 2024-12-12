SRCS = so_long.c event.c texture.c check_map.c utils.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm

MLXPATH = ./MLX42/build

MLX = $(MLXPATH)/libmlx42.a

LIBFT = ./libft/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(MLX):
	make -C $(MLXPATH) all

$(LIBFT):
	make -C libft all

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)

clean:
	make -sC libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re