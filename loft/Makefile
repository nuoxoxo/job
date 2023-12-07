#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  nuo  <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: ____/__/__ __:__:__ by nuo               #+#    #+#              #
#    Updated: ____/__/__ __:__:__ by nuo              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#	the real project must include a rule bonus in Makefile

NAME	=	libft.a
HEADER	=	libft.h
SRC	=	*.c
OBJ	=	*.o
CC	=	gcc -c
CFLAGS	=	-Wall -Werror -Wextra
RM	=	/bin/rm -f

all	:	$(NAME)

$(OBJ)	:	$(SRC) $(HEADER)
		$(CC) $(CFLAGS) $(SRC)

$(NAME)	:	$(OBJ) $(HEADER)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean	:
		$(RM) *.o

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
