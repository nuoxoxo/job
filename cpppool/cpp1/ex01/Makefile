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

comp	:=	c++ -Wall -Werror -Wextra -std=c++98
name	:=	out
rmv	:=	rm -rf

# incl	:=	-I./

src	:=	main.cpp \
		Zombie.cpp \
		ZombieHorde.cpp

bud	:=	$(src:.cpp=.o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\t"
		@ printf "\"hey, are you using the right compiler? \"\n\n"
		@ echo "[ Heap ]"
		@ echo "   ↓" && echo ""
		@ echo "   ↑"
		@ echo "[ Stack ]"

		@ printf "Usage : ./out  [how_many]  [zombie_name] \n\n"

run	:	re
		@ ./out
		@ make clean

all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out

f	:	fclean
re	:	f all
test	:	run

.PHONY	:	fclean clean all re f
