# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 16:30:10 by pdeguing          #+#    #+#              #
#    Updated: 2018/09/13 14:58:05 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAG	= -Wall -Wextra -Werror -c
SRC		= ft_printf/format_char.c \
		  ft_printf/format_conversion.c \
		  ft_printf/format_int.c \
		  ft_printf/format_int_helpers.c \
		  ft_printf/format_str.c \
		  ft_printf/ft_printf.c \
		  ft_printf/get_conversion.c \
		  ft_printf/get_flags.c \
		  ft_printf/get_utf.c \
		  ft_printf/init_conversion.c \
		  ft_printf/print_format.c \
		  libft/ft_atoi.c \
		  libft/ft_bzero.c\
		  libft/ft_capitalize.c\
		  libft/ft_ctostr.c\
		  libft/ft_intlen.c\
		  libft/ft_isalnum.c\
		  libft/ft_isalpha.c\
		  libft/ft_isascii.c\
		  libft/ft_isdigit.c\
		  libft/ft_islower.c\
		  libft/ft_isprint.c\
		  libft/ft_isupper.c\
		  libft/ft_itoa.c\
		  libft/ft_lstadd.c\
		  libft/ft_lstdel.c\
		  libft/ft_lstdelone.c\
		  libft/ft_lstiter.c\
		  libft/ft_lstmap.c\
		  libft/ft_lstnew.c\
		  libft/ft_memalloc.c\
		  libft/ft_memccpy.c\
		  libft/ft_memchr.c\
		  libft/ft_memcmp.c\
		  libft/ft_memcpy.c\
		  libft/ft_memdel.c\
		  libft/ft_memmove.c\
		  libft/ft_memset.c\
		  libft/ft_putchar.c\
		  libft/ft_putchar_fd.c\
		  libft/ft_putendl.c\
		  libft/ft_putendl_fd.c\
		  libft/ft_putnbr.c\
		  libft/ft_putnbr_fd.c\
		  libft/ft_putstr.c\
		  libft/ft_putstr_fd.c\
		  libft/ft_strcat.c\
		  libft/ft_strchr.c\
		  libft/ft_strclr.c\
		  libft/ft_strcmp.c\
		  libft/ft_strcpy.c\
		  libft/ft_strdel.c\
		  libft/ft_strdup.c\
		  libft/ft_strequ.c\
		  libft/ft_strffjoin.c\
		  libft/ft_strfjoin.c\
		  libft/ft_strfljoin.c\
		  libft/ft_striter.c\
		  libft/ft_striteri.c\
		  libft/ft_strjoin.c\
		  libft/ft_strlcat.c\
		  libft/ft_strlen.c\
		  libft/ft_strmap.c\
		  libft/ft_strmapi.c\
		  libft/ft_strncat.c\
		  libft/ft_strncmp.c\
		  libft/ft_strncpy.c\
		  libft/ft_strnequ.c\
		  libft/ft_strnew.c\
		  libft/ft_strnstr.c\
		  libft/ft_strrchr.c\
		  libft/ft_strsplit.c\
		  libft/ft_strstr.c\
		  libft/ft_strsub.c\
		  libft/ft_strtrim.c\
		  libft/ft_tolower.c\
		  libft/ft_toupper.c\
		  libft/ft_uintlen.c\
		  libft/ft_utoa.c\
		  libft/ft_wrdc.c\
		  libft/ft_wrdlen.c

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
	gcc $(INCLUDE) $(TESTSRC) $(LIB)

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
