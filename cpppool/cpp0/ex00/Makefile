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

name		:=	megaphone

# Check compiler requirement before going on

# comp		:=	clang++ -std=c++11 -Wall -Werror -Wextra
# comp		:=	clang++ -std=c++98 -Wall -Werror -Wextra
comp		:=	c++ -std=c++98 -Wall -Werror -Wextra

src		:=	megaphone.cpp
rmv		:=	rm -rf

bud		:=	$(src:.cpp=.o)

all		:	$(name)

%.o		:	%.cpp
			$(comp) -c $<

$(name)		:	$(bud)
			$(comp) -o $@ $<
			@ printf "\n- \n\n"
			@#@ ./$(name)

clean		:
			$(rmv) $(name)

fclean		:	clean
			$(rmv) $(bud)

f		:	fclean

re		:	f all

.PHONY		:	fclean clean all re f
