SRC_DIR = ./srcs/

SRCS =

OBJS = $(SRC:.c=.o)

NAME = pus_swap
MAKE_LIBFT = make -s -C ./libft
LIBFT_A = ./libft/libft.a


${NAME}: ${OBJ}
	${MAKE_LIBFT}
	${CC} ${FLAGS} ${OBJ} ${LIBFT_A} -o ${NAME}