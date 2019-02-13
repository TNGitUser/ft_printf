# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    M                                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 09:51:24 by lucmarti          #+#    #+#              #
#    Updated: 2019/02/13 14:32:35 by lucmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Green=\x1b[32m
End=\x1b[0m

TARGET = libftprintf.a
DEBTARGET = printf

# Might be interesting to look for MAKEFILE patsubst (Text functions)

SRC := ./srcs/main.c ./srcs/ft_printf.c ./srcs/ft_args.c
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
	@$(MAKE) -C libft/
	@gcc $(CFLAGS) $(DEB) libft/libft.a -o $(DEBTARGET) $(OBJ)
	@echo "${Green}libftprintf.a compiled${End}"

clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(TARGET)

re: fclean all
