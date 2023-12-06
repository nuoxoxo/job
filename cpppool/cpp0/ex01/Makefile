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
#* ****************************************************************** nuo *** *#

comp		:=	c++ -std=c++98 -Wall -Werror -Wextra
name		:=	phonebook
src			:=	main.cpp Contact.cpp Phonebook.cpp Utils.cpp
rmv			:=	rm -f

bud			:=	$(src:.cpp=.o)
all			:	$(name)

%.o			:	%.cpp
				@ echo "\ncompiling" [$@]
				$(comp) -c $^

$(name)		:	$(bud)
				@ echo "\ncompiling" [$@]
				$(comp) -o $@ $^
				@ printf "\n- \n\n"

clean		:
				$(rmv) $(name)

fclean		:	clean
				$(rmv) $(bud) out *.out

f			:	fclean
re			:	f all
.PHONY		:	fclean clean all re f
