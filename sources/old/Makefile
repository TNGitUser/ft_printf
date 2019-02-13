# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    M                                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 09:51:24 by lucmarti          #+#    #+#              #
#    Updated: 2019/02/12 13:06:21 by lucmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Green=\x1b[32m
End=\x1b[0m

TARGET = libftprintf.a
DEBTARGET = printf

# Might be interesting to look for MAKEFILE patsubst (Text functions)

SRC :=	./srcs/ft_printf.c ./srcs/main.c ./srcs/ft_memdel.c 	\
	./srcs/ft_hex.c ./srcs/ft_stdconv.c ./srcs/ft_strcat.c  	\
	./srcs/ft_strjoin.c ./srcs/ft_strdup.c ./srcs/ft_strlen.c 	\
	./srcs/ft_args.c ./srcs/ft_format.c ./srcs/ft_ext.c			\
	./srcs/ft_itoa.c ./srcs/ft_bzero.c ./srcs/ft_memalloc.c		\
	./srcs/ft_atoi.c ./srcs/ft_mconv.c ./srcs/ft_fsize.c		\
	./srcs/ft_strsub.c
OBJ = $(SRC:.c=.o)

INCLUDES = ./includes/
CFLAGS = -Wall -Wextra -Werror -g

ifndef VERBOSE
.SILENT:
endif

all: $(TARGET)

$(TARGET): $(OBJ) 
	@gcc $(CFLAGS) $(DEB) -o $(TARGET) $(OBJ)
	@ar -r $(TARGET) $(OBJ)
	@ranlib $(TARGET)
	@echo "${Green}libftprintf.a compiled${End}"

%.o: %.c 
	@gcc $(CFLAGS) $(LIBFLAGS) $(DEB) -o $@ -c $<

.PHONY: deb clean fclean re

deb: $(OBJ) 
	@gcc $(CFLAGS) $(DEB) -o $(DEBTARGET) $(OBJ)
	@echo "${Green}libftprintf.a compiled${End}"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(TARGET)

re: fclean all
