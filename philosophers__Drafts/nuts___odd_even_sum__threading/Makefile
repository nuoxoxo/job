comp	:=	c++ -std=c++11
www	:=	-Wall -Werror -Wextra
name	:=	out
src	:=	odd_even_sum.cpp
bud	:=	$(src:.cpp=.o)


all	:	$(name)

%.o	:	%.cpp
		$(comp) $(www) -c $<


$(name) :	$(bud)
		$(comp) $(www) -o $@ $<
		printf "\n\tosx and linux implement pthread differently\n\n\tthreading in osx might lead to considerably slower performance\n\n"



rmv	:=	rm -rf

clean	:
		$(rmv) *.o
fclean	:	clean
		$(rmv) *.out
		$(rmv) $(name)
f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
