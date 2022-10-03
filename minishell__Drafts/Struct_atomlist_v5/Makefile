comp		:=	cc -Wall -Wextra -Werror -fsanitize=address
rmv		:=	/bin/rm -rf
name		:=	out
src		:=	$(wildcard *.c)
#bud		:=	$(src:.c=.o)
bud		:=	$(src:%.c=tmp/%.o)

# introduce toolkit
lib_path := ../ft_toolkit/
lib_incl := -I $(lib_path) -I./
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
			@ $(comp) $^ -o $@ $(lib_name) -lreadline
			@ cat todo/test.2
			@ make clean
			@#@ printf "\n- \n\n"

clean		:
			@ $(rmv) $(bud)
			@ $(rmv) tmp/
			@ make -C $(lib_path) clean

fclean		:	clean
			@ $(rmv) $(name) out *.o */*.o *.out
			@ make -C $(lib_path) fclean

f		:	fclean
re		:	f all

.PHONY		:	fclean clean all re f
