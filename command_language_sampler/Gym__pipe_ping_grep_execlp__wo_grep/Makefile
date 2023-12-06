comp	=	gcc -Wall -Werror -Wextra -fsanitize=address
rmv	=	rm -rf

src		=	main.c

bud		=	$(src:%.c=%.o)
name	=	$(src:%.c=%)

all		:	$(name)

%.o		:	%.c
		@ echo "compiling [$<]"
		@ $(comp) -c $< -o $@

$(name)	:	$(bud)
		@ echo "compiling [$<]"
		@ $(comp) $< -o $@
		@ make clean
		@ ./$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) main out *.out

f	:	fclean
re	:	f all
.PHONY	:	fclean clean all re f
