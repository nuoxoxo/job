CC		:=	cc -Wall -Wextra -Werror -fsanitize=address
RM		:=	/bin/rm -f
NAME		:=	out

SRC		:=	main.c

BUD		:=	$(SRC:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@ $(CC) -c $^ -o $@

$(NAME)		:	$(BUD)
			@ $(CC) $^ -o $@
			@ printf "\n- \n\n"
			@ printf "Usage: ./out [ number of times moving on up ]\n\n"
			@ make clean

clean		:
			@ $(RM) $(BUD)

fclean		:	clean
			@ $(RM) $(NAME) *.o *.out

f		:	fclean

re		:	fclean all

.PHONY		:	fclean clean all re f

