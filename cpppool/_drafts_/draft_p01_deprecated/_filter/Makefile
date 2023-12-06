comp	:=	c++ -Wall -Werror -Wextra -std=c++98
name	:=	karenFilter
rmv	:=	rm -rf

incl	:=	-I./

src	:=	main.cpp

bud	:=	$(src:.cpp=.o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\t"
		@ printf "\"are you using the right compiler? \"\n\n"
		@ ./$@
		@ printf "\n"
		@ make clean

run	:	re
		@ ./$@
		@ make clean

all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out

f	:	fclean
re	:	f all
test	:	run

.PHONY	:	fclean clean all re f
