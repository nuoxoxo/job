comp	:=	c++ -std=c++98 -Wall -Werror -Wextra
src	:=	main.cpp
name	:=	$(src:.cpp=)

all	:	$(name)

$(name)	:	$(src)
		@ $(comp) $^ -o $@
		@ ./$(name)

f	:
		@ rm -rf $(name) a.out

run	:	re

re	:	f all
