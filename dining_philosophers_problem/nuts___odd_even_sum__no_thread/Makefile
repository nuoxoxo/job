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



rmv	:=	rm -rf

clean	:
		$(rmv) $(name)
fclean	:	clean
		$(rmv) *.out *.o

f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
