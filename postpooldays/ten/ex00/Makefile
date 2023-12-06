NAME	:=	libft.a

HEADER	:=	includes

SRCS	:=	srcs/ft_putchar.c \
    		srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_swap.c

OBJS	:=	${SRCS:c=o}

CC	:=	gcc

CFLAGS	:=	-Wall -Wextra -Werror -I includes

RM	:=	rm -f

${NAME}	:	${OBJS}	
			ar rc	${NAME} ${OBJS}

%.o	:	%.c
			${CC} ${CFLAGS} -c $< -o ${<:c=o}

all	:	${NAME}

clean	:	
		${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re	:	fclean all

.PHONY	:	all clean fclean re
