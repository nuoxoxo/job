NAME	:=	ft_tail
SRCS	:=	${wildcard *.c}
CC	:=	gcc -Wall -Werror -Wextra -I .
$(NAME)	:
		@$(CC) $(SRCS) -o $(NAME)

all	:	$(NAME)
clean	:
		@rm -f $(NAME)
fclean	:	clean
re	:	fclean all
.PHONY	:	all clean fclean re 
