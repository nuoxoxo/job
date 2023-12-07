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

SRC	:=	ft_display_file.c
NAME	:=	ft_display_file
CC	:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra

$(NAME)	:
		@$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean	:
		@/bin/rm -f *.o

fclean	:	clean
		@/bin/rm -f $(NAME)

all	:	@$(NAME)

.PHONY	:	all clean fclean
