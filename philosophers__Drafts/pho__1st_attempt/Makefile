CC		:=	cc -Wall -Wextra -Werror -fsanitize=address
#CC		:=	cc -Wall -Wextra -Werror -fsanitize=thread
RM		:=	/bin/rm -f
NAME		:=	philo

PRF		:=	route_cs.c \
			route_id.c \
			route_p.c \
			route_u.c \
			route_x.c \
			print.c

UTL		:=	ft_checkers.c \
			ft_printers.c \
			ft_atoll.c \
			ft_atoi.c \
			ft_exit.c

STP		:=	setup_table.c \
			setup_philo.c \
			setup_time.c

SRC		:=	main.c \
			dining_philosophers.c \
			philo_event.c \
			$(addprefix print/, $(PRF)) \
			$(addprefix utils/, $(UTL)) \
			$(addprefix setup/, $(STP))


BUD		:=	$(SRC:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			$(CC) -c $< -o $@

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
