LIBMLX = mlx_linux/libmlx_Linux.a -Imlx_linux

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lXext -lX11 -lm -lz

NAME = so_long

SRC =	src/deplacer.c		\
	src/draw.c			\
	src/ft_check_map.c		\
	src/ft_error.c		\
	src/ft_free.c		\
	src/ft_init.c		\
	src/ft_itoa.c		\
	src/ft_key_hook.c		\
	src/ft_putstr.c		\
	src/get_next_line.c		\
	src/get_next_line_utils.c	\
	src/image.c			\
	src/load_xpmfiles.c		\
	src/main.c			\
	src/monde.c			\
	src/parse_map.c	
	
OBJ =	$(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c 
	clang $(CFLAGS) -I -Imlx_linux -c $< -o $@

$(NAME): $(OBJ) 
	make -C mlx_linux
	clang $(CFLAGS) -o $(NAME) $(OBJ) -O3 $(LIBMLX) $(LFLAGS)

clean:
	make clean -C mlx_linux
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
