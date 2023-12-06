#CC		:=	cc -Wall -Wextra -Werror -fsanitize=address
CC		:=	cc -Wall -Wextra -Werror -fsanitize=thread  -pthread
RM		:=	/bin/rm -f
NAME		:=	philo
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
			$(CC) $(INC) -c $< -o $@

$(NAME)		:	$(BUD)
			$(CC) $(BUD) -o $@
			@printf "\n- \n"
			@./$(NAME)

clean		:
			$(RM) $(BUD)
fclean		:	clean
			$(RM) $(NAME) *.o */*.o
f		:	fclean
re		:	fclean all
.PHONY		:	fclean clean all re f
