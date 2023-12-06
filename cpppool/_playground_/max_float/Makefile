comp		:=	c++ -Wall -Werror -Wextra -std=c++98
name		:=	out
rmv		:=	rm -rf

src		:=	main.cc

budfolder	:=	./bud/
budpath		:=	$(budfolder)
bud		:=	$(addprefix $(budfolder), $(src:.cc=.o))

all		:	$(name)

$(budpath)	:
			@ mkdir -p $(budpath)


$(budfolder)%.o	:	%.cc
			@ echo "compiling [$^] "
			@ $(comp) -c $< -o $@

$(name)	:	$(budpath) $(bud)
		@ echo "compiling [$@]"
		@ $(comp) $(bud) -o $@
		@ printf "\n\t"
		@ printf "\"are you using the right compiler? \"\n\n"
		@ echo "you can do [make f] "
		@ echo "you can do [make run] "
		@ echo ""
		@ echo "----------- use valgrind ---------- "
		@ echo ""

run	:	re
		@ ./out
		@ make clean


r	:	run

clean	:
		@ $(rmv) $(budfolder)

fclean	:	clean
		@ $(rmv) $(name) a.out *.o


test	:	run
f	:	fclean
ff	:	fclean
		$(rmv) *_shrubbery
re	:	f all

.PHONY	:	fclean clean all re f

