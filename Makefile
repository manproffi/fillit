# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 12:01:32 by sprotsen          #+#    #+#              #
#    Updated: 2016/12/17 12:01:36 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = f1.c f2.c f3.c f4.c f5.c f6.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(FLAG) $(OBJ) -o $(NAME)

%.o: %.c
	gcc $(FLAG) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all	