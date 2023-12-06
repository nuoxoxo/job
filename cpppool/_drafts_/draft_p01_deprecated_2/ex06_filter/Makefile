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
name	:=	karenFilter
rmv	:=	rm -rf

incl	:=	-I./


src	:=	main.cpp \
		Karen.cpp

#path	:=	src/
#src	:=	$(foreach cpp, $(src), $(path)$(cpp))
#src	+=	main.c

bud	:=	$(src:.cpp=.o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\t"
		@ printf "\"hey, are you using the right compiler? \"\n\n"

run	:	re
		@ ./$@
		@ make clean

all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) out *.out 

f	:	fclean
re	:	f all
test	:	run

.PHONY	:	fclean clean all re f

