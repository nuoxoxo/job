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

$(name)		:	$(budpath) $(bud)
			@ echo "compiling [$@]"
			@ echo "compiling [$^]"
			@ $(comp) $(bud) -o $@
			@ echo ""
			@ ./out
			@ make clean

clean		:
			@ $(rmv) $(budfolder)

fclean	:	clean
			@ $(rmv) $(name) a.out *.o

f		:	fclean
re		:	f all

.PHONY		:	fclean clean all re f
