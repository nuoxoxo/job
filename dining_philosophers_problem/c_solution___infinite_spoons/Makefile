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
#* *************************************************************** .py .sh *** *#

cc	:=	cc #-Wall -Wextra -Werror

main	:=	philo.c
name	:=	$(main:.c=)
utl	:=	philo_actions.c \
		philo_utils.c
src	:=	$(main) $(utl)
bud	:=	$(src:.c=.o)

%.o	:	%.c
	$(cc) -c $< -o $@
$(name)	:	$(bud)
	$(cc) $(bud) -o $@
all	:	$(name)
f	:	fclean
re	:	fclean all
	./philo 5 10
clean	:
	rm -f $(bud)
fclean	:	clean
	rm -f $(name)
d	:	fclean
	rm -f *.o main test

.PHONY	:	fclean clean all re f d
