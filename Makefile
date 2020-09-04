NAME = BSQ
SRCS = srcs/find_sq.c srcs/main.c srcs/output.c srcs/print_result.c srcs/read_map.c srcs/subsidiary.c srcs/term.c
CFLAGS = -Werror -Wextra -Wall
OBJS = ${SRCS:.c=.o}
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${OBJS} -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
