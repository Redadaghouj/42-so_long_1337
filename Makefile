CC := cc

CFLAGS := -Wall -Wextra -Werror

MLX_FLAGS := -framework Cocoa -framework OpenGL -framework IOKit

MLX_LIB := -lglfw3

MLXINCLUDE := -I./MLX42/ -L./MLX42

AMLX := ./MLX42/libmlx42.a

RM := rm -f

NAME := so_long

SRCS := so_long.c

OBJ := ${SRCS.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${SRCS} ${MLX_FLAGS} ${MLX_LIB} ${AMLX} ${MLXINCLUDE} -o ${NAME}

%.o: %.c so_long.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re