comp		:=	c++ -Wall -Werror -Wextra -std=c++98
name		:=	out
rmv		:=	rm -rf

src		:=	Bureaucrat.cpp \
			_Cpp05_.cpp \
			main.cpp

budfolder	:=	./bud/
budpath		:=	$(budfolder)
bud		:=	$(addprefix $(budfolder), $(src:.cpp=.o))

all		:	$(name)

$(budpath)	:
			@ mkdir -p $(budpath)


$(budfolder)%.o	:	%.cpp
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
		@ echo "---------- do valgrind ----------- "
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
re	:	f all

.PHONY	:	fclean clean all re f
