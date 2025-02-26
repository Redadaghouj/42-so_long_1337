CC := cc

CFLAGS := -Wall -Wextra -Werror -w

MLX_FLAGS := -framework Cocoa -framework OpenGL -framework IOKit

MLX_LIB := -lglfw3

MLXINCLUDE := -I./MLX42/ -L./MLX42

AMLX := ./MLX42/libmlx42.a

RM := rm -f

NAME := so_long

MANDO := mandatory

UTILS := mandatory/utils

GNL := mandatory/gnl

SRCS := ${MANDO}/so_long.c ${UTILS}/ft_putstr_fd.c ${GNL}/get_next_line.c ${GNL}/get_next_line_utils.c \
		${MANDO}/validate_map.c

all: ${NAME}

${NAME}: ${SRCS} ${MANDO}/so_long.h ${GNL}/get_next_line.h
	${CC} ${CFLAGS} ${SRCS} ${MLX_FLAGS} ${MLX_LIB} ${AMLX} ${MLXINCLUDE} -o ${NAME}

clean:
	@echo "CLEAN"

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re