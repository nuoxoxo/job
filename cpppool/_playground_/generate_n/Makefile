comp	:=	c++ -std=c++17 -Wall -Werror -Wextra
src	:=	main.cc
name	:=	$(src:.cc=)

all	:	$(name)

$(name)	:	$(src)
		@ $(comp) $^ -o $@
		@ ./$(name)

f	:
		@ rm -rf $(name) a.out

run	:	re
re	:	f all
