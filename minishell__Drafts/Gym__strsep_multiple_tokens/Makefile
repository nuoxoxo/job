comp		:=	cc -Wall -Wextra -Werror -fsanitize=address
rmv		:=	/bin/rm -f
name		:=	out
src		:=	main.c
bud		:=	$(src:.c=.o)
all		:	$(name)

%.o		:	%.c
			@ $(comp) -c $^ -o $@

$(name)		:	$(bud)
			@ $(comp) $^ -o $@
			@ printf "\n- \n\n"
			@ printf "Usage: ./$(name)  [ string ]  [ delimiter_char ] \n\n"

clean		:
			$(rmv) $(bud)

fclean		:	clean
			$(rmv) $(name) *.o */*.o *.out

f		:	fclean

re		:	fclean all

.PHONY		:	fclean clean all re f

