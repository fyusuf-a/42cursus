NAME = libft.a

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
SRCS	+= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS  += ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRCS  += ft_atoi_strict.c ft_elem.c ft_strcmp.c math_utilities.c

OBJS = ${SRCS:.c=.o}

C_FLAGS = -Werror -Wextra -Wall

INCLUDES = -I.

all:		${NAME}

$(NAME):	${OBJS}
	ar -rcs ${NAME} ${OBJS}
	make -C printf
	make -C get_next_line
	rm -rf .temp
	mkdir .temp
	cd .temp ; ar -x ../printf/libftprintf.a ; ar -x ../get_next_line/libget_next_line.a
	ar -rcs ${NAME} .temp/*.o
	rm -rf .temp
	

clean:
	rm -f *.gch
	make -C printf clean
	make -C get_next_line clean
	rm -f ${OBJS} ${OBJS_BONUS} ${OBJS_TESTS}

fclean: clean
	make -C printf fclean
	make -C get_next_line fclean
	rm -f ${NAME}

re:		fclean all

.c.o:
	gcc ${C_FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

.PHONY:	all clean fclean re printf get_next_line
