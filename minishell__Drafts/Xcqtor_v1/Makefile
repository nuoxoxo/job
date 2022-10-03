#comp		:=	cc -Wall -Wextra -Werror -fsanitize=address
comp		:=	cc -Wall -Wextra -Werror
rmv		:=	/bin/rm -rf
name		:=	out
src		:=	$(wildcard *.c)
#bud		:=	$(src:.c=.o)
bud		:=	$(src:%.c=tmp/%.o)

# introduce toolkit
lib_path := ../ft_toolkit/
# lib_incl := -I $(lib_path) -I./
lib_incl := -I $(lib_path)
lib_name := $(lib_path)ft_toolkit.a

# introduce readline
rl		:=	-I/Users/$(USER)/.brew/opt/readline/include

all		:	$(name)

tmp/%.o		:	%.c
			@ mkdir -p tmp
			@ echo "compiling [$@]"
			@ $(comp) $(lib_incl) -c $^ -o $@ $(rl)

$(name)		:	$(bud)
			@ make -C $(lib_path)
			@ echo "compiling [$<]"
			@ $(comp)  $^ -o $@  $(lib_name) -lreadline
			@ cat todo/input_sample.0
			@ make clean
			@ printf "\e[36mthis program can do: \e[0;0m\n"
			@ printf "export\n"
			@ printf "exit (done in this ver.)\n"
			@ printf "pwd\n"
			@ printf "cd\n"
			@ printf "env\n"
			@ printf "echo\n"
			@ printf "unset\n"
			@ printf "\e[36m(prints code if exits properly)\n \e[0;0m"
			@ printf "\n"

clean		:
			@ $(rmv) $(bud)
			@ $(rmv) tmp/
			@#@ make -C $(lib_path) clean

fclean		:	clean
			@ $(rmv) $(name) out *.o */*.o *.out
			@#@ make -C $(lib_path) fclean

f		:	fclean
re		:	f all

.PHONY		:	fclean clean all re f
