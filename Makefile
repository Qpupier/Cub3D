# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 15:48:25 by qpupier           #+#    #+#              #
#    Updated: 2021/02/03 15:47:09 by qpupier          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
INC_PATH = includes
SRC_PATH = sources
OBJ_PATH = .objects
SRC_SUP = parsing
SRC_NAME = 	error.c 						\
			free.c 							\
			main.c 							\
			parsing/parsing.c 				\
			parsing/parsing_map.c 			\
			parsing/parsing_parameters.c 	\
			parsing/parsing_size_colors.c 	\
			parsing/parsing_textures.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = cub3d.h structs.h functions.h
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))
LIBS = -L libft -L .
LDFLAGS = -O3 -march=native -flto -ffast-math
LDLIBS = -lm -lmlx -lft
ifeq ($(OS), Windows_NT)
	NORMINETTE = ~/.norminette/norminette.rb
	MINILIBX =
	OS = $(PINK)Windows
else
	OS = $(shell uname -s)
	ifeq ($(OS), Darwin)
		NORMINETTE = norminette
		MINILIBX = -framework OpenGL -framework AppKit -framework OpenAL
		OS = $(END)$(PINK)Mac OS
	else
		ifeq ($(OS), Linux)
			NORMINETTE = ~/.norminette/norminette.rb
			MINILIBX =
			OS = $(END)$(PINK)Linux
		else
			OS = $(RED)This OS is not supported
		endif
	endif
endif
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(LDFLAGS)
CPPFLAGS = -I $(INC_PATH) -I libft/$(INC_PATH) -I mlx

ERASE = 	\033[2K\r
GREY = 		\033[30m
RED = 		\033[31m
GREEN = 	\033[32m
YELLOW = 	\033[33m
BLUE = 		\033[34m
PINK = 		\033[35m
CYAN = 		\033[36m
WHITE = 	\033[37m
END = 		\033[0m
BOLD = 		\033[1m
UNDER = 	\033[4m
SUR = 		\033[7m

.PHONY: all compilation clean fclean re norme

all: compilation $(NAME)
ifeq ($(OS), $(RED)This OS is not supported)
	@printf "$(BLUE)> $(NAME) : $(RED)Project fail !$(END)\n"
else
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"
endif

compilation:
	@make -C libft

$(NAME): $(OBJ)
ifneq ($(OS), $(RED)This OS is not supported)
	@$(CC) $(CFLAGS) $(LIBS) $(MINILIBX) $(LDLIBS) $^ -o $@
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"
endif

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC) libft/libft.a
	@mkdir -p $(OBJ_PATH) $(addprefix $(OBJ_PATH)/,$(SRC_SUP))
ifeq ($(OS), $(RED)This OS is not supported)
	@touch $@
else
	@printf "$(ERASE)$(YELLOW)$(BOLD)[COMPILE] $(END) $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
endif

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)$(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME) $(NAME).exe
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

norme:
ifeq ($(OS), $(RED)This OS is not supported)
	@printf "Norminette is not supported\n"
else
	$(NORMINETTE) libft/$(INC_PATH) libft/$(SRC_PATH) $(INC_PATH) $(SRC_PATH)
endif
