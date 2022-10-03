RM	=	/bin/rm -f
PF	=	printf

NAME	=	fractol

OGL	=	-framework OpenGL -framework AppKit
FS	=	-fsanitize=address
CC	=	gcc

FG	=	-Wall -Wextra -Werror $(FS)#			toggle on osx
#FG	=	-Wall -Wextra -Werror#				toggle on ubu

#MLX	=	./mlx/libmlx.a -lXext -lX11 -lm -lz#		toggle on ubu
#MLX	=	./mlx/libmlx.a -lXext -lX11 -lm -lz $(OGL)#	toggle on osx
MLX	=	$(OGL) -lmlx -Lmlx -lm -lz#			toggle on osx - alt method


SRC	=	$(wildcard ft_printf/*.c) \
		$(wildcard ft_utils/*.c) \
		$(wildcard *.c)

BUD	=	$(SRC:.c=.o)

MSG	=	@$(PF) "\
/* ************************************************************************** */\n\
/*                                                                            */\n\
/*                            \\ \\            /\`/\`\`                            */\n\
/*                            ~\o o_       0 0\                               */\n\
/*                            / \__)      (u  ); _  _                         */\n\
/*                     / \/ \/  /           \  \/ \/ \                        */\n\
/*                    /(   . . )            (         )\                      */\n\
/*                   /  \_____/              \_______/  \                     */\n\
/*                       []  []               [[] [[]    *.                   */\n\
/*                       []] []]              [[] [[]                         */\n\
/*                                                                            */\n\
/* ****************************************************************** nuo *** */\n"

all	:	$(NAME)

%.o	:	%.c
		$(CC) $(FG) -c $< -o $@

$(NAME)	:	$(BUD)
		$(CC) $(FG) $(BUD) $(MLX) -o $(NAME)

clean	:
		$(RM) $(BUD) *.o

fclean	:	clean
		$(RM) $(NAME)
		@$(MSG)

re	:	fclean all

.PHONY	:	fclean clean all re
