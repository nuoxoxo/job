CC		:=	cc -Wall -Wextra -Werror -fsanitize=address
RM		:=	/bin/rm -f
NAME		:=	a.out

SRC		:=	main.c

BUD		:=	$(SRC:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@ $(CC) -c $^ -o $@

$(NAME)		:	$(BUD)
			@ $(CC) $^ -o $@
			@ printf "\n- \n\n"

clean		:
			$(RM) $(BUD)

fclean		:	clean
			$(RM) $(NAME) main *.o */*.o *.out

f		:	fclean

re		:	fclean all

.PHONY		:	fclean clean all re f

