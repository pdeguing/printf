# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/11 17:16:33 by pdeguing          #+#    #+#              #
#    Updated: 2018/08/11 18:28:03 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
CFLAG = -Wall -Wextra -Werror
SRC = main.c printf.c
INCLUDE = -I /libft
LIB = -lft -L./libft/
LIBFT = libft/libft.a
NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
WARN_COLOR = \x1b[33;01m

all: $(NAME)
	@ echo "all: $(OK_COLOR)done$(NO_COLOR)"

$(NAME): $(LIBFT)
	@ gcc -o $(NAME) $(CFLAG) $(INCLUDE) $(SRC) $(LIB)
	@ echo "$(NAME): $(OK_COLOR)done$(NO_COLOR)"

$(LIBFT):
	@ cd libft/ && make
	@ echo "$(LIBFT): $(OK_COLOR)done$(NO_COLOR)"

clean:
	@ /bin/rm -f *.o
	@ cd libft/ && make clean
	@ echo "clean: $(OK_COLOR)done$(NO_COLOR)"

fclean: clean
	@ /bin/rm -f $(NAME)
	@ cd libft/ && make fclean
	@ echo "fclean: $(OK_COLOR)done$(NO_COLOR)"

re: fclean all
	@ echo "re: $(OK_COLOR)done$(NO_COLOR)"

.PHONY: clean fclean all re
