SRC_FILES = libc_function/ft_isalpha.c \
	libc_function/ft_isdigit.c \
	libc_function/ft_isalnum.c \
	libc_function/ft_isascii.c \
	libc_function/ft_isprint.c \
	libc_function/ft_strlen.c \
	libc_function/ft_memset.c \
	libc_function/ft_bzero.c \
	libc_function/ft_memcpy.c \
	libc_function/ft_memmove.c \
	libc_function/ft_strlcpy.c \
	libc_function/ft_strlcat.c \
	libc_function/ft_toupper.c \
	libc_function/ft_tolower.c \
	libc_function/ft_strchr.c \
	libc_function/ft_strrchr.c \
	libc_function/ft_strncmp.c \
	libc_function/ft_memchr.c \
	libc_function/ft_memcmp.c \
	libc_function/ft_strnstr.c \
	libc_function/ft_atoi.c \
	libc_function/ft_calloc.c \
	libc_function/ft_strdup.c \
	supplementary_function/ft_substr.c \
	supplementary_function/ft_strjoin.c \
	supplementary_function/ft_strtrim.c \
	supplementary_function/ft_split.c \
	supplementary_function/ft_itoa.c \
	supplementary_function/ft_strmapi.c \
	supplementary_function/ft_striteri.c \
	supplementary_function/ft_putchar_fd.c \
	supplementary_function/ft_putstr_fd.c  \
	supplementary_function/ft_putendl_fd.c \
	supplementary_function/ft_putnbr_fd.c \
	chain_list/ft_lstnew.c \
	chain_list/ft_lstadd_front.c \
	chain_list/ft_lstsize.c \
	chain_list/ft_lstlast.c \
	chain_list/ft_lstadd_back.c \
	chain_list/ft_lstdelone.c \
	chain_list/ft_lstclear.c \
	chain_list/ft_lstiter.c \
	chain_list/ft_lstmap.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_utils_1.c \
	ft_printf/ft_utils_2.c \
	get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJECT_FILES = $(SRC_FILES:.c=.o)

AR = ar -rcs

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	@$(AR) $(NAME) $(OBJECT_FILES)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(OBJECT_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re
