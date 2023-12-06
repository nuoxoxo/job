comp		:=	cc -Wall -Wextra -Werror -fsanitize=address
rmv		:=	/bin/rm -f
name		:=	out
src		:=	main.c
bud		:=	$(src:.c=.o)

all		:	$(name)

%.o		:	%.c
			@ $(comp) -c $< -o $@

$(name)		:	$(bud)
			$(comp) -lreadline $^ -o $@
			@ printf "\n- \n\n"
			@ printf "Usage: "
			@ printf "\t./$(name) \n"
			@ printf "\t./$(name) more \n"
			@ printf "\t./$(name) less \n"
			@ printf "\n- \n\nhave fun. \n\n"

clean		:
			$(rmv) $(name)

fclean		:	clean
			$(rmv) $(bud) out *.o */*.o *.out env 

f		:	fclean
re		:	f all

.PHONY		:	fclean clean all re f
