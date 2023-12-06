name	=	out
src	=	main.c
rmv	=	rm -rf
comp	=	gcc -Wall -Werror -Wextra -fsanitize=address
all	:	$(name)

$(name)	:	$(src)
		$(comp) $< -o $@
		@printf " \n- \n\n"
		@printf "The unistd.h header file defines the following macros. \nThey are constants that map to the file descriptors of the standard streams: \n\nSTDIN_FILENO\n\tStandard input, stdin (value 0) \n\nSTDOUT_FILENO\n\tStandard output, stdout (value 1) \n\nSTDERR_FILENO\n\tStandard error, stderr (value 2) \n\n- \n\n"

fclean	:
		$(rmv) out *.o *.out

f	:	fclean
re	:	f all

.PHONY	:	re fclean f all
