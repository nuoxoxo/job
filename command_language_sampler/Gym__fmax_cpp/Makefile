name	=	out
comp	=	c++ -std=c++98 -Wall -Werror -Wextra
rmv	=	rm -f
src	=	main.cpp
bud	=	$(src:cpp=o)
all	:	$(name)
%.o	:	%.c
		$(comp) -c $< -o $@
$(name)	:	$(bud)
		$(comp) $< -o $@
		@ printf "\n- \n\n"
clean	:
		$(rmv) $(bud)

fclean	:	clean
		$(rmv) $(name)

f	:	fclean
re	:	f all
.PHONY	:	fclean clean all re f
