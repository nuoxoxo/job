NAME	:=	ft_display_file
CC	:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra
SRC	:=	ft_display_file.c

$(NAME)	:
		@$(CC) $(CFLAGS) -o $(NAME) $(SRC)
all	:	@$(NAME)
clean	:
		@/bin/rm -f *.o
fclean	:	clean
		@/bin/rm -f $(NAME)
.PHONY	:	all clean fclean

# clean removes .o files
# fclean removes .o files and the binary
