comp	:=	c++ -std=c++11 -Wall -Werror -Wextra
rmv	:=	rm -rf
name	:=	out

src	:=	stars_align.cpp

bud	:=	$(src:%.cpp=%.o)

all	:	$(name)

%.o	:	%.cpp
		@ $(comp) -c $< -o $@

$(name)	:	$(bud)
		@ $(comp) $< -o $@
		@#@ ./out < stars_align.1
		@ ./out < stars_align.0
		@ make f

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) main out *.out *.o

f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
