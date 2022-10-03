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

name	=	fractol
bone	=	fractol_bonus
rm	=	/bin/rm -f
p	=	printf
mlx	=	./mlx/libmlx.a

www	=	-Wall -Wextra -Werror
fs	=	-fsanitize=address
ogl	=	-framework OpenGL -framework AppKit # osx main solution
ogl	=	-framework OpenGL -framework AppKit -lmlx -Lmlx -lm -lz # osx alt.

#<!---		README: Uncomment either one	--->#

#flag	=	$(www) $(fs) $(ogl)				# osx
flag	=	$(www) -lXext -lX11 -lm -lz	# ubu

u	=	ft_calculation.c \
		ft_cleaner.c \
		ft_colors.c \
		ft_events.c \
		ft_init_fractal.c \
		ft_init_julia.c \
		ft_init_hooks.c \
		ft_init_vars.c \
		ft_init_window.c \
		ft_looper.c \
		ft_movements.c \
		ft_panel.c \
		main.c

pf	=	ft_printf.c \
		route_cs.c \
		route_id.c \
		route_p.c \
		route_u.c \
		route_x.c

ft	=	ft_putstr.c \
		ft_strcmp.c


src	=	$(addprefix ft_printf/, $(pf)) \
		$(addprefix ft_utils/, $(ft)) \
		$(u)

bud	=	$(src:.c=.o)

all	:	$(name)
%.o	:	%.c
		@cc $(www) -c $< -o $@

$(name)	:	$(bud)
		@make -C mlx
		@cc $(flag) $(bud) $(mlx) -o $@
		@$(p) "\nFitter, happier, use valgrind. \n\n"

$(bone):	$(bud)
		@make -C mlx
		@cc $(flag) $(bud) $(mlx) -o $@
		@$(p) "\nThink different, do valgrind. \n\n"

clean	:
		$(rm) $(bud) *.o ft_printf/*.o ft_utils/*.o

f	:	clean
fclean	:	clean
		$(rm) $(name) $(bone)
		@$(p) "\nI am Valgrind. Before the universe was, I am. \n\n"

bonus	:	$(bone)
f	:	fclean
re	:	fclean all
rebonus:	fclean $(bone)

.PHONY	:	fclean clean all re f
