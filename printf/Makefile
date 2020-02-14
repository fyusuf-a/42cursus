NAME	= libftprintf.a

SRCS		= ft_printf.c parse_format.c parse_format2.c print.c print_str.c print_int.c print_int2.c utilities.c utilities2.c
SRCS	 += format.c print_nothing.c print_double.c print_double2.c print_scientific.c print_g.c
OBJS		= ${SRCS:.c=.o}
$(OBJS): EXTRA_ARGS := -Werror -Wextra -Wall

TESTS		= test/main.c
OBJS_TESTS	= ${TESTS:.c=.o}
$(OBJS_TESTS): EXTRA_ARGS := -Wall -Wextra

all:	${NAME}

bonus:		${NAME}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

cclean:		clean
	rm -f test/test.o ${OBJS_TESTS}

fclean:		clean
	rm -f ${NAME}

re:		fclean all

$(NAME):	${OBJS}
	ar -rcs ${NAME} ${OBJS}

.c.o:
	gcc ${EXTRA_ARGS} -I. -c $< -o ${<:.c=.o}

test:		${NAME}
	gcc ${EXTRA_ARGS} -I. -o test/test ${NAME} test/main.c
	test/test

.PHONY:	all clean fclean re test bonus libft
