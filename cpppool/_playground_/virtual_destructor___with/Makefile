name	=	out
comp	=	clang++ -Wall -Werror -Wextra -std=c++98
rmv	=	rm -f
src	=	main.cpp
bud	=	$(src:cpp=o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $< -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n"
		@ ./$@
		@ make clean

run	:	re
		@ ./out
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
