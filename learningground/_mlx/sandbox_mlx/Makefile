CC	:= 	cc
PF	:=	printf
RM	:=	/bin/rm -f
FSA	:=	-fsanitize=address
FLG	:=	-Wall -Wextra -Werror
#FLG	:=	-Wall -Wextra -Werror $(FSA)

#OGL	:=	-framework OpenGL -framework AppKit		# toggle on for macos
#MLX	:=	./mlx/libmlx.a -lXext -lX11 -lm -lz $(OGL)	# toggle on for macos

MLX	:=	./mlx/libmlx.a -lXext -lX11 -lm -lz		# switch on for linux

#SRC	:=	main.c
#SRC	=	main1_nocheck_display.c
#SRC	=	main2_nocheck_window.c
#SRC	=	main3_checkerror_destroy.c
#SRC	=	main4_destroy_image.c
#SRC	=	main5_cleaner.c
SRC	=	main6_loophook.c

BUD	=	$(SRC:.c=.o)
NAME	=	$(SRC:.c=)

%.o	:	%.c
		$(CC) $(FLG) -c $< -o $@

all	:	$(NAME)

$(NAME)	:	$(BUD)
		$(CC) $(FG) $(BUD) -o $(NAME) $(MLX)
		@$(PF) "\nFitter, happier, use valgrind. \n\n"

clean	:
		$(RM) *.o

fclean	:	clean
		$(RM) $(NAME)
		@$(PF) "\n“I am Valgrind. Before the universe was, I am.”\n\n"

re	:	fclean all

.PHONY	:	all clean fclean re
