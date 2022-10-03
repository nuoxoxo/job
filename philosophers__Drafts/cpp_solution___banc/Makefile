cc:=	c++ -Wall -Wextra -Werror -std=c++11
src:=	solution_banc.cpp
bud:=	$(src:.cpp=.o)
exe:=	$(src:.cpp=)

%.o:	%.cpp
	@$(cc) -c $< -o $@
$(exe):	$(bud)
	@$(cc) $< -o $(exe) 
	@printf " \n\\\"remove the time delays, let it \
	run longer and philosophers start to starve.\\\" \n\n"
	@./solution_banc

f:	fclean
re:	fclean all
clean:
	rm -f $(bud)
fclean:	clean
	rm -f *.o *.out $(exe)

.PHONY:	fclean clean all re f

