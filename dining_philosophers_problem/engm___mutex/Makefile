#flag	:=	-Wall -Werror -Wextra -lpthread -lm
#flag	:=	-Wall -Werror -Wextra -pthread

flag	:=	-Wall -Werror -Wextra
all	:	main

%.o	:	%.c
		gcc $(flag) -c $< -o $@

main	:	main.o
		@gcc $(flag) $< -o $@
		@printf " \ntotal counts: \n"
		@./main | wc -l
		@printf "(w/o mutex, output differs "
		@printf "at each run and always exceeds target) \n"
		@printf " \nrun with: ./pthread | wc -l \n\n"

f	:	fclean
re	:	fclean all
clean	:
		rm -f *.o
fclean	:	clean
		rm -f main
.PHONY	:	fclean clean all re
