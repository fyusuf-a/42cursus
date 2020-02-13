NAME	= libft.a

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
SRCS	+= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS	+= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c
SRCS	+= ft_base.c

BONUS	=

TESTS	=

OBJS = ${SRCS:.c=.o}
$(OBJS): EXTRA_FLAGS := -Werror -Wextra -Wall

OBJS_BONUS = ${BONUS:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
	ar -rcs ${NAME} ${OBJS}

bonus:		${NAME} ${OBJS_BONUS}
	ar -rcs ${NAME} ${OBJS_BONUS}

clean:
	rm -f ${OBJS} ${OBJS_BONUS} ${OBJS_TESTS}

fclean:		clean
	rm -f ${NAME}

re:		fclean all

.c.o:
	gcc ${EXTRA_FLAGS} ${EXTRA_INCLUDES} -I. -c $< -o ${<:.c=.o}

.PHONY:	all clean fclean re bonus
