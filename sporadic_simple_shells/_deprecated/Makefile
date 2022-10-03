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


libft_path	:=	./utils_basic/
libft_incl	:=	-I $(libft_path) -I ./
libft_name	:=	$(libft_path)utils_basic.a


BRAIN		:=	start_shell.c \
			on_exit.c

SIGNAL		:=	catch_signal.c

src		:=	$(addprefix ./brain/, $(BRAIN)) \
			$(addprefix ./signal/, $(SIGNAL)) \
			main.c

bud		:=	$(src:c=o)

all		:	$(name)

$(name)		:	$(bud)
			@ make -C $(libft_path)
			@ $(comp) -o $@ $^ $(libft_name) $(RL) -lreadline
			@ printf "\n- \nthis shell needs libf (incl. print & gnl)" 
			@ printf "renamed to utils_basic as dependency\n -\n\n"

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
