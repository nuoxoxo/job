flag	:=	-Wall -Werror -Wextra
rm	:=	/bin/rm -rf
p	:=	printf
src	:=	main.c
bud	:=	$(src:.c=.o)
name	:=	$(src:.c=)

all	:	$(name)

%.o	:	%.c
		gcc $(flag) -c $< -o $@

$(name)	:	$(bud)
		@gcc $(flag) -lpthread -lm $< -o $@
		@#@gcc $(flag) $< -o $@ # works w/o pthread flags
		gcc $(flag) $< -o $@
		./main
		@$(p) " \nw/o joining, program ends when main thread ends \n"
		@$(p) " \nnow program ends when either thread terminates \n"
		@$(p) " \ntry: \n\n./main n1 n2 \n\n"

clean	:
		@$(rm) *.o

fclean	:	clean
		@$(rm) $(name) a.out test

f	:	fclean
re	:	fclean all
.PHONY	:	fclean clean all re f
