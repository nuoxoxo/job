#* ************************************************************************** *#
#*                                                                            *#
#*                            \\             #`#``                            *#
#*                            ~\o o_       0 0\                               *#
#*                            # \__)      (u  ); _  _                         *#
#*                     # \# \#  #           \  \# \# \                        *#
#*                    #(   . . )            (         )\                      *#
#*                   #  \_____#              \_______#  \                     *#
#*                       []  []               [[] [[]    *.                   *#
#*                       []] []]              [[] [[]                         *#
#*                                                                            *#
#* ****************************************************************** .py *** *#

name		:=	out
comp		:=	gcc -Wall -Wextra -Werror -fsanitize=address
rmv		:=	/bin/rm -f

#RL		:=	-lreadline
#RL		:=	-lreadline -L /usr/local/Cellar/readline/8.1.2/lib \
			-I /usr/local/Cellar/readline/8.1.2/include/readline
RL		:=	-I/Users/$(USER)/.brew/opt/readline/include 

#src := main.c
src		:=	_test.c
libft_path	:=	./../ft_toolkit/
libft_incl	:=	-I $(libft_path)
libft_name	:=	$(libft_path)ft_toolkit.a
bud		:=	$(src:.c=.o)

all		:	$(name)

$(name)		:	$(bud)
			@ make -C $(libft_path)
			@ $(comp) -o $@ $^ $(RL) $(libft_name) -lreadline
			@ printf "\n- \n\n"

%.o		:	%.c
			@ $(comp) $(RL) $(libft_incl) -c $< -o $@ 

clean		:
			@ make -C $(libft_path) clean
			@ $(rmv) $(bud)

fclean		:	clean
			@ make -C $(libft_path) fclean
			@ $(rmv) $(name) *.o */*.o *.out

f		:	fclean
re		:	fclean all

.PHONY		:	fclean clean all re f
