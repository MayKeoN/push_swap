#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/11 02:22:25 by ymonfray          #+#    #+#              #
#    Updated: 2015/07/11 02:22:25 by ymonfray         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

SRC =	src/push_swap_init.c\
		src/push_swap_main.c\
		src/push_swap_op.c\
		src/push_swap.c
		# src/push_swap_list.c\

INC = -I include
 # -I libft/include -I /opt/X11/include/X11

# LIB = -L libft/ -lft -L minilibx_macos/ -lmlx 

OBJ = $(SRC:.c=.o)

FLAG = -O1

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(INC)

%.o: %.c
	$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all