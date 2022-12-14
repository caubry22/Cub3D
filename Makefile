CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = cub3d

SRC =	srcs/main.c\
		srcs/parsing/parsing.c\
		srcs/parsing/parsing_utils.c\
		srcs/parsing/check_texture.c\
		srcs/parsing/check_color.c\
		srcs/parsing/check_map_valid.c\
		srcs/parsing/check_map_closed.c\
		srcs/libft/printf/ft_printf.c\
		srcs/libft/printf/ft_printf_utils.c\
		srcs/libft/get_next_line.c\
		srcs/libft/isdigit.c\
		srcs/libft/split.c\
		srcs/libft/strchr.c\
		srcs/libft/strcmp.c\
		srcs/libft/strdup.c\
		srcs/libft/strjoin.c\
		srcs/libft/strlen.c\
		srcs/libft/strtrim.c\
		srcs/player.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $(OBJ) -Lmlx_linux -L/usr/lib -Imlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o $@

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re: fclean all
