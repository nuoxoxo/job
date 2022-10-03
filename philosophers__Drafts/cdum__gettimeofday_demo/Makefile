CC		:=	cc -Wall -Wextra -Werror -fsanitize=address
RM		:=	/bin/rm -f
NAME		:=	demo

SRC		:=	demo.c 

BUD		:=	$(SRC:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			$(CC) -c $< -o $@

$(NAME)		:	$(BUD)
			$(CC) $(BUD) -o $@
			@printf "\n- \n\n"
			@./$(NAME)

clean		:
			$(RM) $(BUD)
fclean		:	clean
			$(RM) $(NAME)
f		:	fclean
re		:	fclean all
.PHONY		:	fclean clean all re f
