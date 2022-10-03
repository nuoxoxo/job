CC		:=	cc -Wall -Wextra -Werror -fsanitize=address
RM		:=	/bin/rm -f
NAME		:=	out


SRC		:=	main.c

BUD		:=	$(SRC:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@$(CC) -c $< -o $@

$(NAME)	:	$(BUD)
		$(CC) $< -o $@
		@ printf "\n- \n\n"
		@ printf "Usage: \n"
		@ printf "\t ./out  __Haystack (string)__  __Needle (char)__ \n\n"
		@ printf "\t ./out \n"
		@ printf "\t (* edit infile to try different haystack) \n\n"

clean		:
			$(RM) $(BUD)

fclean		:	clean
			$(RM) $(NAME) *.o */*.o *.out

f		:	fclean

re		:	fclean all

.PHONY		:	fclean clean all re f
