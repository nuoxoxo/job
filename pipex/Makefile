name		:=	pipex
comp		:=	cc -Wall -Wextra -Werror -fsanitize=address
rmv		:=	rm -rf
src		:=	$(wildcard *.c)
bud		:=	$(src:%.c=obj/%.o)

#%.o		:	%.c
obj/%.o		:	%.c
			@ mkdir -p obj
			@ echo "compiling [$^]"
			@ $(comp) -c $^ -o $@

$(name)		:	$(bud)
			@ echo "compiling [$@]"
			@ $(comp) $^ -o $@


clean		:
			@ $(rmv) $(bud)
			@ $(rmv) obj/

fclean		:	@ clean
			@ $(rmv) $(name)

all		:	$(name)
f		:	fclean
re		:	f all

.PHONY		:	fclean clean all re f
