CC	=	cc
RM	=	/bin/rm -rf
FG	=	-Wall -Werror -Wextra -fsanitize=address

SRC	=	$(wildcard ./*.c)
BUD	=	$(SRC:.c=.o)

NAME	=	main

%.o : %.c
	$(CC) $(FG) -c $< -o $@

all	:	$(NAME)

$(NAME)	:	$(BUD)
	$(CC) $(FG) $(BUD) -o $(NAME)

clean	:
	$(RM) $(BUD)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
