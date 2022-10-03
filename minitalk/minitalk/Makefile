CC	=	gcc
FG	=	-Wall -Werror -Wextra -fsanitize=address
RM	=	/bin/rm -f
PS	=	$(wildcard ./ft_printf/*.c)
#PO	=	$(PS:.c=.o)
US	=	$(wildcard ./ft_utils/*.c)
#UO	=	$(US:.c=.o)
S	=	server
C	=	client

all	:
		@printf "$(MI)$(R) initializing client and server ...\n"
		@$(CC) $(FG) server.c $(US) $(PS) -o server
		@$(CC) $(FG) client.c $(US) $(PS) -o client
		@#@printf "$(MS)$(R)$(G'1) server built successfully $(R)\n"
		@#@printf "$(MS)$(R)$(G'1) client built successfully $(R)\n"
		@printf "$(MS)$(R) server built successfully $(R)\n"
		@printf "$(MS)$(R) client built successfully $(R)\n"

clean	:
		@$(RM) $(S) $(C)
		@#@printf "$(BW)$(R)$(BIG) all executables cleaned $(R)\n"
		@#@printf "$(MI)$(R)$(Y'1) all executables cleaned $(R)\n"
		@printf "$(MI)$(R) all executables cleaned $(R)\n"

fclean	:	clean
		@$(RM) *.o 
		@cd ft_printf && $(RM) *.o
		@cd ft_utils && $(RM) *.o
		@#@printf "$(BW)$(R)$(BIG) all executables and object files cleaned $(R)\n"
		@#@printf "$(MI)$(R)$(Y'1) all executables and object files cleaned $(R)\n"
		@printf "$(MI)$(R) all executables and object files cleaned $(R)\n"

re	:	fclean all

.PHONY	:	all clean fclean re

MS	=	[$(G'1)Success$(G'1)]
MI	=	[$(Y'1)Message$(Y'1)]
BIG	=	\e[1;3;32m	# bold italic green
BG	=	\e[1;32m	# bold green
#BW	=	\e[1;97m
BW	=	\e[97m
R	=	\e[0;0m
F	=	\e[2m		# faint
Y	=	\e[1;3;3m
G'1	=	\e[92m
G'2	=	\e[1;32m
Y'1	=	\e[36m
Y'2	=	\e[36m


