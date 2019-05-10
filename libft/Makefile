# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmarti <lucmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 15:37:09 by lucmarti          #+#    #+#              #
#    Updated: 2019/05/09 14:24:53 by lucmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef ECHO
#T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
#	-nrRf $(firstword $(MAKEFILE_LIST)) \
#	ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
T = $(words $(SRC))
N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "\r	[`expr $C '*' 100 / $T`%]\c"
endif

NAME = libft.a

SRC := 	./ft_atoi.c
SRC += 	./ft_bzero.c
SRC +=	./ft_itoa.c
SRC +=	./ft_ltoa.c
SRC +=	./ft_ultoa.c
SRC +=	./ft_ftoa.c
SRC +=	./ft_memdel.c
SRC +=	./ft_putchar.c
SRC +=	./ft_putchar_fd.c
SRC +=	./ft_putendl.c
SRC +=	./ft_putendl_fd.c
SRC +=	./ft_putnbr.c
SRC +=	./ft_putnbr_fd.c
SRC +=	./ft_putstr.c
SRC +=	./ft_putstr_fd.c
SRC +=	./ft_strcat.c
SRC +=	./ft_strcmp.c
SRC +=	./ft_strdup.c
SRC +=	./ft_strlen.c
SRC +=	./ft_power.c
SRC +=	./ft_abs.c
SRC +=	./ft_putstrn.c
SRC +=	./ft_strjoinf.c
SRC +=	./ft_strjoin.c
SRC +=	./ft_strchr.c
SRC +=	./ft_straddc.c
SRC +=	./ft_memalloc.c

# This is a minimal set of ANSI/VT100 color codes
_END=\x1b[0m
_BOLD=\x1b[1m
_UNDER=\x1b[4m
_REV=\x1b[7m

# Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

OBJ_PATH = ./objs
OBJ_FILE = $(SRC:.c=.o)

DEP_FILE = $(SRC:.c=.d)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILE))
DEP = $(addprefix $(OBJ_PATH)/,$(DEP_FILE))

ifndef VERBOSE
.SILENT:
VERBOSE = 0
endif

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) libft.h
	@echo "\rCompilation of $(_CYAN)libft$(_END)   :    $(_GREEN)Done${_END}"
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: %.c libft.h 
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc -Wall -Wextra -Werror -g -o $@ -c $<
	@$(ECHO)
ifeq ("$(VERBOSE)","1")
	@echo "[${_YELLOW}libft${_END}][${_GREEN}Compiled${_END}] : $<"
endif

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@rm -f $(DEP)
	@rmdir $(OBJ_PATH) 2> /dev/null || (true && if [ -d "$(OBJ_PATH)" ]; then\
		echo "$(Red)ERROR$(End)	: $(OBJ_PATH) is not empty."; fi)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEP)
