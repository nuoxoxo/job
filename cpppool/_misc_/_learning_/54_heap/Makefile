comp	:=	c++ -std=c++11 -Wall -Werror -Wextra
src	:=	main.cpp
# src	:=	main___minor_difference_with_added_scope.cpp
name	:=	a.out

all	:	$(name)

$(name)	:	$(src)
		@ $(comp) $^ -o $@
		@ ./$(name)
		@ make f

f	:
		@ rm -rf $(name) a.out

run	:	re
re	:	f all
