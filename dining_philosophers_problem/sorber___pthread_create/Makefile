#flag	:=	-Wall -Werror -Wextra
flag	:=
rm	:=	/bin/rm -rf
p	:=	printf
src	:=	main.c
bud	:=	$(src:.c=.o)
name	:=	$(src:.c=)

all	:	$(name)

%.o	:	%.c
		gcc $(flag) -c $< -o $@

$(name)	:	$(bud)
		@gcc $(flag) $< -lpthread -lm -o $@
		@#@gcc $(flag) $(bud) -o $@ # works even w/o pthread flags
		@./$(name)
		@printf " \n\t print_left \t- "
		@printf "side thread routine made with pt_create \n"
		@printf " \n\t print_right \t- "
		@printf "main thread \n"
		@printf " \n\t try: \n\t ./main  n1  n2 \n\n"
		@printf "\t n1 : how many arrows on Side thread \n"
		@printf "\t n2 : how many arrows on Main thread \n\n"

clean	:
		@$(rm) *.o

fclean	:	clean
		@$(rm) $(name) a.out test

f	:	fclean
re	:	fclean all
.PHONY	:	fclean clean all re f
