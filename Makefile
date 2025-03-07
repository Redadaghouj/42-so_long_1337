CC := cc

# CFLAGS := -Wall -Wextra -Werror
CFLAGS := -Wall -Wextra -Werror -fsanitize=address
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

NAME_BNS := so_long_bonus

BNS := bonus

UTILS_BNS := bonus/utils_bonus

GNL_BNS := bonus/gnl_bonus

SRCS := ${MANDO}/so_long.c ${MANDO}/validate_map.c ${MANDO}/check_walls.c ${MANDO}/print_steps.c \
		${MANDO}/validate_map_utils.c ${MANDO}/display_frame.c ${MANDO}/display_frame_utils.c \
		${UTILS}/error_handlers.c ${UTILS}/ft_strcmp.c ${UTILS}/ft_putstr_fd.c ${UTILS}/ft_putchar.c \
		${GNL}/get_next_line.c ${GNL}/get_next_line_utils.c

SRCS_BNS := ${BNS}/so_long_bonus.c ${BNS}/validate_map_bonus.c ${BNS}/check_walls_bonus.c ${BNS}/print_steps_bonus.c \
		${BNS}/validate_map_utils_bonus.c ${BNS}/display_frame_bonus.c ${BNS}/display_frame_utils_bonus.c \
		${UTILS_BNS}/error_handlers_bonus.c ${UTILS_BNS}/ft_strcmp_bonus.c ${UTILS_BNS}/ft_putstr_fd_bonus.c \
		${UTILS_BNS}/ft_putchar_bonus.c \
		${GNL_BNS}/get_next_line_bonus.c ${GNL_BNS}/get_next_line_utils_bonus.c

OBJS := ${SRCS:.c=.o}

OBJS_BNS := ${SRCS_BNS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${MANDO}/so_long.h ${GNL}/get_next_line.h
	${CC} ${CFLAGS} ${MLX_FLAGS} ${MLX_LIB} ${AMLX} ${MLXINCLUDE} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

bonus: ${NAME_BNS}

${NAME_BNS}: ${OBJS_BNS} ${BNS}/so_long_bonus.h ${GNL_BNS}/get_next_line_bonus.h
	${CC} ${CFLAGS} ${MLX_FLAGS} ${MLX_LIB} ${AMLX} ${MLXINCLUDE} ${OBJS_BNS} -o ${NAME_BNS}

bonus/%.o: bonus/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS} ${OBJS_BNS}

fclean: clean
	@${RM} ${NAME} ${NAME_BNS}

re: fclean all

.PHONY: all clean fclean re