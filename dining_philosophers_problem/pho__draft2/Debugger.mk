CC		:=	cc -Wall -Wextra -Werror -fsanitize=address
#CC		:=	cc -Wall -Wextra -Werror -fsanitize=thread
RM		:=	/bin/rm -f
NAME		:=	philo

PRINT		:=	route_cs.c \
			route_id.c \
			route_p.c \
			route_u.c \
			route_x.c \
			print.c

U		:=	ft_atoi.c \
			ft_atoll.c \
			$(addprefix print/, $(PRINT))

S		:=	parsers.c \
			checkers.c \
			cleaners.c \
			printers.c \
			fetch_time.c \
			usage_exit.c \

P		:=	philo_jobs.c \
			philo_sims.c \
			philo_print.c


SRC		:=	utils/debugger.c \
			$(addprefix simulation/, $(P)) \
			$(addprefix setup/, $(S)) \
			$(addprefix utils/, $(U))

BUD		:=	$(SRC:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@$(CC) -c $< -o $@

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
