comp	:=	c++ -Wall -Werror -Wextra -std=c++98
name	:=	out
rmv	:=	rm -rf
src	:=	main.cpp Fixed.cpp
bud	:=	$(src:%.cpp=%.o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\t"
		@ printf "\"are you using the right compiler? \"\n\n"
		@ printf "see a demo if you like \n\n"
		@ printf "\thttps://github.com/nuoxoxo/fixed_py3_demo \n\n"
		@ echo "you can do [make f] "
		@ echo "you can do [make run] "
		@ echo ""

run	:	re
		@ ./out
		@ make clean

all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out

test	:	run
f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
