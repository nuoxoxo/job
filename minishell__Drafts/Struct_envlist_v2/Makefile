comp		:=	cc -Wall -Wextra -Werror -fsanitize=address
rmv		:=	/bin/rm -rf
name		:=	out
src		:=	$(wildcard *.c)
bud		:=	$(src:%.c=tmp/%.o)

all		:	$(name)

tmp/%.o		:	%.c
			@ mkdir -p tmp
			@ echo "compiling [$@]"
			@ $(comp) -c $^ -o $@

$(name)		:	$(bud)
			@ echo "compiling [$<]"
			@ $(comp) $^ -o $@
			@ printf "\n- \n\n"
			@ printf "try this: \n"
			@ printf "env >> log1 && ./$(name) >> log2 && diff -s log1 log2 \n"
			@ printf "\n- \n\n"
			@#@ make clean

clean		:
			@ $(rmv) $(bud)
			@ $(rmv) tmp/

fclean		:	clean
			@ $(rmv) $(name) out *.o */*.o *.out log*

f		:	fclean
re		:	f all

.PHONY		:	fclean clean all re f
