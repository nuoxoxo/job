comp		:=	cc -Wall -Wextra -Werror # -fsanitize=address
rmv		:=	/bin/rm -f
name		:=	out
src		:=	$(wildcard *.c)
bud		:=	$(src:.c=.o)

all		:	$(name)

%.o		:	%.c
			@ echo "compiling [$@]"
			@ $(comp) -c $^ -o $@ -I/Users/$(USER)/.brew/opt/readline/include

$(name)		:	$(bud)
			@ echo "compiling [$<]"
			@ $(comp) $^ -o $@ -lreadline
			@ printf "\n- \n\n"
			@ printf "try something long, eg. \n\n"
			@ printf "< infile cmd1 | sort | grep w -R . | cmd2 > log2 | sort | wc -l "
			@ printf "\n\n- \n\n"
			@ make clean

clean		:
			@ $(rmv) $(bud)

fclean		:	clean
			@ $(rmv) $(name) out *.o */*.o *.out

f		:	fclean
re		:	f all

.PHONY		:	fclean clean all re f
