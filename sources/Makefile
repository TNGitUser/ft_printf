# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    M                                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 09:51:24 by lucmarti          #+#    #+#              #
#    Updated: 2019/03/06 11:18:18 by lucmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Green=\x1b[32m
Cyan=\x1b[36m
End=\x1b[0m

TARGET = libftprintf.a
DEBTARGET = printf

SRC_PATH = ./src
SRC_FILE := ft_printf.c ft_args.c ft_stdc.c ft_hex.c ft_stdc2.c
SRC_FILE += ft_eflag.c ft_format.c ft_print_string.c ft_print_int.c

OBJ_PATH = ./objs
OBJ_FILE = $(SRC_FILE:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILE))

CPPFLAGS = -I includes -I libft
CFLAGS = -Wall -Wextra #-Werror 

ifndef VERBOSE
.SILENT:
endif

all: $(TARGET)

$(TARGET): $(OBJ) 
	@$(MAKE) -C libft/
	@gcc $(CFLAGS) libft/libft.a -o $(TARGET) $(OBJ)
	@ar -r $(TARGET) $(OBJ)
	@ranlib $(TARGET)
	@echo "Compilation of $(Cyan)$(TARGET)$(End) :       $(Green)done${End}"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c ./includes/
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAGS) -c $< $(CPPFLAGS) -o $@

.PHONY: deb clean fclean re

deb: $(OBJ)
	@$(MAKE) -C libft/
	@gcc $(CFLAGS) $(CPPFLAGS) $(DEB) ./src/main.c libft/libft.a -o $(DEBTARGET) $(OBJ)
	@echo "Compilation of $(Cyan)$(DEBTARGET)$(End)  :       $(Green)done${End}"

clean:
	@$(MAKE) -C libft/ clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rm -f $(OBJ)
	@echo "Printf : Removing objects"

fcleand: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(DEBTARGET)
	@echo "Printf : Removing printf"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(TARGET)
	@echo "Printf : Removing libftprintf.a"

re: fclean all
