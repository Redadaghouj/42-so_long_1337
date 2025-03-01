CC := cc

CFLAGS := -Wall -Wextra -Werror -fsanitize=address
# CFLAGS := -Wall -Wextra -Werror -fsanitize=address
# CFLAGS := -Wall -Wextra -Werror -w -fsanitize=address
# CFLAGS := -Wall -Wextra -Werror -w

MLX_FLAGS := -framework Cocoa -framework OpenGL -framework IOKit

MLX_LIB := -lglfw3

MLXINCLUDE := -I./MLX42/ -L./MLX42

AMLX := ./MLX42/libmlx42.a

RM := rm -f

NAME := so_long

MANDO := mandatory

UTILS := mandatory/utils

GNL := mandatory/gnl

SRCS := ${MANDO}/so_long.c ${MANDO}/validate_map.c ${MANDO}/so_long_utils.c ${MANDO}/check_walls.c \
		${MANDO}/validate_map_utils.c ${MANDO}/player.c \
		${GNL}/get_next_line.c ${GNL}/get_next_line_utils.c \
		${UTILS}/error_handlers.c ${UTILS}/ft_strcmp.c ${UTILS}/ft_putstr_fd.c

all: ${NAME}

${NAME}: ${SRCS} ${MANDO}/so_long.h ${GNL}/get_next_line.h
	${CC} ${CFLAGS} ${SRCS} ${MLX_FLAGS} ${MLX_LIB} ${AMLX} ${MLXINCLUDE} -o ${NAME}

clean:
	@echo "CLEAN"

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re