NAME	= libftprintf.a

SRCS		= ft_printf_main.c ft_printf_main2.c ft_printf_parse_format.c ft_printf_parse_format2.c ft_printf_print.c ft_printf_print_str.c ft_printf_print_int.c ft_printf_print_int2.c ft_printf_utilities.c
SRCS	 += ft_printf_utilities2.c ft_printf_format.c ft_printf_print_nothing.c ft_printf_print_double.c ft_printf_print_double2.c ft_printf_print_scientific.c ft_printf_print_g.c
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

test:		${NAME} test/main.c
	gcc ${EXTRA_ARGS} -I. -o test/test test/main.c ${NAME}
	test/test

.PHONY:	all clean fclean cclean re test bonus libft
