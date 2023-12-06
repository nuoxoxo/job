NAME	:=	do-op
SRCS	:=	$(wildcard *.c)
#SRCS	:=	do-op.c utils_o.c utils_s.c
#SRCS	:=	$(*.c)
#OBJS	:=	$(SRC:c=o)
CC	:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra -I .
RM	:=	rm -f

do-op	:	$(SRCS)
		@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
all	:	@$(NAME)
clean	:	
		@$(RM) $(NAME)
