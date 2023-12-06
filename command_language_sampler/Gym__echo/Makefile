CC		:=	cc -Wall -Wextra -Werror -fsanitize=address
RM		:=	/bin/rm -f
NAME		:=	out


SRC		:=	main.c

BUD		:=	$(SRC:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@$(CC) -c $< -o $@

$(NAME)		:	$(BUD)
			$(CC) -lreadline $(BUD) -o $@
			@printf "\n- \n\nUsage: ./$(NAME) [no argument]\n"
			@printf "\n*default mode: echo without -n \n\n"

clean		:
			$(RM) $(BUD)

fclean		:	clean
			$(RM) $(NAME) *.o */*.o *.out minishell

f		:	fclean

re		:	fclean all

.PHONY		:	fclean clean all re f
