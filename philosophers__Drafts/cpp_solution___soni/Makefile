cc:=	c++ -Wall -Wextra -Werror -std=c++2a
src:=	solution_soni.cpp
bud:=	$(src:.cpp=.o)
exe:=	$(src:.cpp=)

%.o:	%.cpp
	@$(cc) -c $< -o $@
$(exe):	$(bud)
	@$(cc) $< -o $(exe)
	@printf " \n\\\"I think, therefore ymmv.\\\"\n\n"
	@./solution_soni

f:	fclean
re:	fclean all
clean:
	rm -f $(bud)
fclean:	clean
	rm -f *.o *.out $(exe)

.PHONY:	fclean clean all re f
