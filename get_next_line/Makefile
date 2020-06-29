NAME	= libget_next_line.a

SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= ${SRCS:.c=.o}
$(OBJS): EXTRA_ARGS := -Werror -Wextra -Wall -O3

all:	${NAME}

bonus:		${NAME}

clean:
	rm -f *.gch
	rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
	rm -f ${NAME}

re:		fclean all

$(NAME):	${OBJS}
	ar -rcs ${NAME} ${OBJS}

.c.o:
	gcc ${EXTRA_ARGS} -I. -c $< -o ${<:.c=.o}

test:		${NAME} test/main.c
	gcc ${EXTRA_ARGS} -o test/test test/main.c ${NAME}
	test/test

.PHONY:	all clean fclean re ${NAME}
