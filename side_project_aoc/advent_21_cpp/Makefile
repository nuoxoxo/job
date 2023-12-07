comp	:=	c++ -std=c++98 -Wall -Werror -Wextra
rmv	:=	rm -rf
name	:=	out

src	:=	aoc2101_sonar_long.cpp
src	:=	aoc2101_sonar.cpp
src	:=	aoc2102_dive_recent.cpp
src	:=	aoc2102_dive.cpp

bud	:=	$(src:%.cpp=%.o)

all	:	$(name)

%.o	:	%.cpp
		@ $(comp) -c $< -o $@

$(name)	:	$(bud)
		@ $(comp) $< -o $@
		@#@ ./out < ../input/2101.0
		@ ./out < aoc2102_dive.0
		@ make f

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) main out *.out *.o

f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f

