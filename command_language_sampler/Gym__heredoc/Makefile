cc	:=	c++ -Wall -Wextra -Werror -std=c++11

src	:=	main.cpp
bud	:=	$(src:.cpp=.o)
exe	:=	$(src:.cpp=)

%.o	:	%.cpp
	@ $(cc) -c $< -o $@

$(exe)	:	$(bud)
	@ $(cc) $< -o $(exe)
	@ echo "compiling [$<]"
	@ make clean

f	:	fclean
re	:	fclean $(exe)

clean	:
	@ rm -f $(bud)

fclean	:	clean
	@ echo "deleting [$(exe)]"
	@ rm -f *.o *.out $(exe)
	@ echo "deleting [$(bud)]"

.PHONY	:	fclean clean all re f

