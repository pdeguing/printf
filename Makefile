# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 16:30:10 by pdeguing          #+#    #+#              #
#    Updated: 2018/09/11 19:58:35 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAG	= -Wall -Wextra -Werror -c
SRC		= ft_printf/*.c libft/*.c
OBJ		= *.o
TESTSRC = ft_printf/*.c
INCLUDE = -I /libft
LIB = -lft -L./libft/
LIBFT = libft/libft.a


all: $(NAME)

$(NAME): 
	gcc  $(CFLAG) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
	cd libft/ && make clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft/ && make fclean

re: fclean all

# TO RUN TEST

test: $(LIBFT)
	gcc $(INCLUDE) $(SRC) $(LIB)

$(LIBFT):
	cd libft/ && make

tclean:
	/bin/rm -f *.o
	cd libft/ && make clean

tfclean: clean
	/bin/rm -f a.out 
	cd libft/ && make fclean

tre: tfclean test 


.PHONY: clean fclean all re
