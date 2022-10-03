NAME		:=	philo

#CC		:=	cc -Wall -Wextra -Werror -g -pthread
#CC		:=	cc -Wall -Wextra -Werror -g -fsanitize=address
CC		:=	cc -Wall -Wextra -Werror -g -pthread -fsanitize=thread

RM		:=	/bin/rm -f
INC		:=	-I./

PRINT		:=	route_cs.c \
			route_id.c \
			route_p.c \
			route_u.c \
			route_x.c \
			print.c

U		:=	ft_atoi.c \
			ft_atoll.c \
			ft_current_ms.c \
			ft_minmax.c \
			$(addprefix print/, $(PRINT))

H		:=	parsers.c \
			checkers.c \
			cleaners.c \
			printers.c \
			usage_exit.c

P		:=	philo_jobs.c \
			philo_sims.c \
			philo_print.c


SRC		:=	main.c \
			$(addprefix utils/, $(U)) \
			$(addprefix helpers/, $(H)) \
			$(addprefix simulation/, $(P))

BUD		:=	$(SRC:%.c=%.o)

all		:	$(NAME)

%.o		:	%.c
			@ $(CC) $(INC) -c $< -o $@
			@ echo "compiling [$@]"

$(NAME)		:	$(BUD)
			@ $(CC) $(BUD) -o $@
			@ echo "compiling [$@]"
			@ printf "\n- \n\n"
			@ make c
			@ cat testsuite/helgrind.0
			@ ./$(NAME)
			@ printf "\n- \n\n"


clean		:
			@ $(RM) $(BUD)

fclean		:	clean
			@ $(RM) $(NAME) *.o */*.o

c		: 	clean	
f		:	fclean
re		:	fclean all
.PHONY		:	fclean clean all re f c
