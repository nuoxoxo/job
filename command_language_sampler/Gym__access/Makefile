comp	=	cc -Wall -Werror -Wextra -fsanitize=address
rmv	=	rm -rf
src	=	main.c

bud	=	$(src:%.c=%.o)
name	=	$(src:%.c=%)

all	:	$(name)

%.o	:	%.c
		@ $(comp) -c $< -o $@

$(name)	:	$(bud)
		@ $(comp) $< -o $@
		@ echo "compiling [$<]"
		@ ./$(name)

clean	:
		@$(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) main out *.out in.0

f	:	fclean
re	:	f
		@ touch in.0
		@ make
.PHONY	:	fclean clean all re f
