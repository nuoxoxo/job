NAME	:=	ft_cat
CC	:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra
SRC	:=	ft_cat.c
$(NAME)	:
		@$(CC) $(CFLAGS) -o $(NAME) $(SRC)
all	:	@$(NAME)
clean	:
		@/bin/rm -f *.o
fclean	:	clean
		@/bin/rm -f $(NAME)
.PHONY	:	all clean fclean
