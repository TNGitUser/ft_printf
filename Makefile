# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 15:42:43 by lucmarti          #+#    #+#              #
#    Updated: 2019/04/30 13:41:52 by lucmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Red=\x1b[31m
Green=\x1b[32m
Cyan=\x1b[36m
Yellow=\x1b[34m
End=\x1b[0m

NAME = libftprintf.a

SRC_PATH = ./src
SRC_FILE = main.c ft_printf.c error.c init.c parser.c bool.c peacemaker.c\
		   hex.c print.c get_csp.c get_iuox.c print_int.c

OBJ_PATH = ./objs
OBJ_FILE = $(SRC_FILE:.c=.o)
DEPS_FILE = $(SRC_FILE:.c=.d)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILE))
DEPS = $(addprefix $(OBJ_PATH)/,$(DEPS_FILE))

CFLAGS = -Wall -Wextra -g3 -I./includes -I./libft
CPPFLAGS = -MMD -MP
LIB = $(OBJ_PATH)/libft.a

ifndef VERBOSE
.SILENT:
VERBOSE=0
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ./libft "VERBOSE=$(VERBOSE)"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@cp -a libft/libft.a $(OBJ_PATH)/libft.a
	@ar -rc $(NAME) $(OBJ) $(LIB)
	@ranlib $(NAME)
	@echo "Compilation of $(Cyan)$(NAME)$(End)   :    ${Green}Done${End}"

ft_printf: $(OBJ)
	@$(MAKE) -C ./libft "VERBOSE=$(VERBOSE)"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@cp -a libft/libft.a $(OBJ_PATH)/libft.a
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "Compilation of $(Cyan)ft_printf$(End)   :    ${Green}Done${End}"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "[${Green}Compiled${End}] : $<"

libft: 
	@$(MAKE) -C ./libft "VERBOSE=$(VERBOSE)"
	@cp -a libft/libft.a $(OBJ_PATH)/libft.a

.PHONY: clean fclean miniclean minire re

clean:
	@rm -f $(OBJ)
	@rm -f $(LIB)
	@$(RM) $(DEPS)
	@$(MAKE) -C ./libft/ clean 
	@rmdir $(OBJ_PATH) 2> /dev/null || (true && if [ -d "$(OBJ_PATH)" ]; then\
		echo "$(Red)ERROR$(End)	: $(OBJ_PATH) is not empty."; fi)
	@echo "$(Red)$(NAME)$(End) : Removing objects"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ./libft/ fclean 
	@echo "$(Red)$(NAME)$(End) : Removing $(NAME)"

miniclean:
	@rm -f $(OBJ)

minire: miniclean all

re: fclean all
-include $(DEPS)
