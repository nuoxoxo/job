#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  nuo  <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: ____/__/__ __:__:__ by nuo               #+#    #+#              #
#    Updated: 2022/11/11 14:46:18 by nuxu             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a
HEADER	=	libft.h

SRC	=	$(filter-out $(wildcard ft_lst*.c), $(wildcard *.c))
OBJ	=	$(SRC:.c=.o)
#OBJ	=	*.o

BSRC	=	$(wildcard ft_lst*.c)
BOBJ	=	$(BSRC:.c=.o)

CC	=	gcc -c
CFLAGS	=	-Wall -Werror -Wextra

RM	=	/bin/rm -f


so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)


$(NAME)	:	$(OBJ) $(HEADER)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all	:	$(NAME)

bonus	:	$(BOBJ) $(OBJ) $(HEADER)
		ar rc $(NAME) $(BOBJ) $(OBJ)
		ranlib $(NAME)

$(OBJ)	:	$(SRC) $(HEADER)
		$(CC) $(CFLAGS) $(SRC)

$(BOBJ)	:	$(SRC) $(BSRC) $(HEADER)
		$(CC) $(CFLAGS) $(SRC) $(BSRC)

clean	:
		$(RM) *.o

f	:	fclean
fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

rebonus :	fclean bonus

.PHONY	:	all clean fclean re
