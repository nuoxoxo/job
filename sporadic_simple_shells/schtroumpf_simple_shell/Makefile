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

cc		:=	cc -Wall -Wextra -Werror -fsanitize=address
#cc		:=	cc -Wall -Wextra -Werror
rmv		:=	/bin/rm -f
name		:=	smurf
rl_incl		:=	-I/Users/$(USER)/.brew/opt/readline/include 
rl		:=	-lreadline
src		:=	main.c

bud		:=	$(src:.c=.o)

all		:	$(name)

%.o		:	%.c
			@ $(cc) -c $^ -o $@ $(rl_incl)

$(name)		:	$(bud)
			@ $(cc) $^ -o $@ $(rl)
			@ printf "Usage: ./minishell \n\n- \n\n"

clean		:
			@ $(rmv) $(bud)

fclean		:	clean
			@ $(rmv) $(name) *.o */*.o *.out minishell smurf

f		:	fclean

re		:	fclean all

.PHONY		:	fclean clean all re f

