# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuxu <nuxu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 16:34:04 by nuxu              #+#    #+#              #
#    Updated: 2022/11/14 13:43:33 by nuxu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME	:= test

SRCS	:= Account.cpp \
		tests.cpp \

OBJS	:= $(SRCS:%.cpp=%.o)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -c 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
