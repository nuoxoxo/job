rmv	=	rm -rf
all	:
		gcc -Wall -Wextra -Werror main.c
		@ make clean
		@ ./a.out
clean	:
		@ $(rmv) *.o
fclean	:	clean
		@ $(rmv) *.out
f	:	fclean
.PHONY	:	fclean clean f all
