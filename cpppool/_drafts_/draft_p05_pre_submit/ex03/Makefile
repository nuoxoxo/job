comp		:=	c++ -Wall -Werror -Wextra -std=c++98
name		:=	out
rmv		:=	rm -rf

src		:=	main.cpp \
			AForm.cpp \
			Bureaucrat.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			PresidentialPardonForm.cpp \
			Intern.cpp \
			_Cpp05_.cpp

budfolder	:=	./bud/
budpath		:=	$(budfolder)
bud		:=	$(addprefix $(budfolder), $(src:.cpp=.o))

all		:	$(name)

$(budpath)	:
			@ mkdir -p $(budpath)


$(budfolder)%.o	:	%.cpp
			@ echo "compiling [$^] "
			@ $(comp) -c $< -o $@

$(name)	:	$(budpath) $(bud)
		@ echo "compiling [$@]"
		@ $(comp) $(bud) -o $@
		@ printf "\n\t"
		@ printf "\"are you using the right compiler? \"\n\n"
		@ echo "you can do [make f] "
		@ echo "you can do [make run] "
		@ echo ""
		@ echo "--------------------- "
		@ echo ""

run	:	re
		@ ./out
		@ make clean


r	:	run

clean	:
		@ $(rmv) $(budfolder)

fclean	:	clean
		@ $(rmv) $(name) a.out *.o


test	:	run
f	:	fclean
ff	:	fclean
		$(rmv) *_shrubbery
re	:	f all

.PHONY	:	fclean clean all re f
