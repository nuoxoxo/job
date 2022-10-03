
comp	=	gcc -Wall -Wextra -Werror

src	=	print_i.c

ubu	=	" \n\tFor Linux the correct command is: \n\n\t\t gcc -pthread \n"
msg	=	" \n\tmain thread & side quest run concurrently \n\n"


bud	=	$(src:.c=.o)
name	=	outfile


%.o	:	%.c
		$(comp) -c $< -o $@

all	:	$(name)

$(name)	:	$(bud) 
		$(comp) -pthread -lm $< -o $@
		@printf $(ubu)
		@printf $(msg)
		@./$(name)

# above looked like this before: 
# $(comp) -lpthread -lm $< -o $@


f	:	fclean
re	:	f all

clean	:
		rm -f $(bud)

fclean	:	clean
		rm -f *.o $(name) out print_i random_ab mutex_lock dead_lock

.PHONY	:	fclean clean all re f
