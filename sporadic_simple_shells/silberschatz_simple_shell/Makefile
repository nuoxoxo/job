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

name	:= 	out
#comp	:=	gcc -Wall -Werror -Wextra
comp	:=	gcc -Wall -Werror -Wextra -fsanitize=address
rmv	:=	rm -rf
src	:=	main.c
bud	:=	$(src:.c=.o)

%.o	:	%.c
		@ echo "compiling [$^]"
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@]"
		@ $(comp) $^ -o $@
		@ make clean
		@ printf " \n------8<------ [ cut ] ------------ \n\n"
		@ printf "testcases : \n\n"
		@ cat testcases
		@ printf "\n"


all	:	$(name)
run	:	all
		@ ./out
clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name)

f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
