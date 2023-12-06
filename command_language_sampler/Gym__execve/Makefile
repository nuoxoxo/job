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
			@ printf "you can try: \n\n"
			@ printf "./out /bin/cat _*_ \n"
			@ printf "./out /bin/ls -l \n"
			@ printf "./out /bin/ls -l | awk \'{print $$ 9}\' \n"
			@ printf "./out /bin/pwd \n"
			@ printf "./out /usr/bin/env \n"
			@ printf "./out /usr/bin/whoami \n"
			@ printf "./out /usr/bin/whereis _*_ \n"
			@ printf "\n"

clean		:
			$(RM) $(BUD)

fclean		:	clean
			$(RM) $(NAME) *.o */*.o *.out

f		:	fclean

re		:	fclean all

.PHONY		:	fclean clean all re f

