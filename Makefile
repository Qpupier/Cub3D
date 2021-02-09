# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 15:48:25 by qpupier           #+#    #+#              #
#    Updated: 2021/02/09 16:20:42 by qpupier          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
INC_PATH	=	includes
SRC_PATH	=	sources
OBJ_PATH	=	.objects
DIR			=	parsing 	\
				parsing/textures
SRC_NAME	=	parsing/textures/parsing_textures_no_so.c 	\
				parsing/textures/parsing_textures_s.c 		\
				parsing/textures/parsing_textures_we_ea.c 	\
				parsing/parsing.c 							\
				parsing/parsing_error.c 					\
				parsing/parsing_map.c 						\
				parsing/parsing_parameters.c 				\
				parsing/parsing_size_colors.c 				\
				error.c 									\
				free.c 										\
				main.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
INC_NAME	=	cub3d.h 	\
				structs.h 	\
				functions.h
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC			=	$(addprefix $(INC_PATH)/,$(INC_NAME))
LDFLAGS		=	-O3 -march=native -flto -ffast-math

ifeq ($(OS), Windows_NT)
	LIBS		=	-L libft -L mlx
	LDLIBS		=	-lm -lmlx -lft
	DLIBS		=	libft/libft.a
	NORMINETTE	=	~/.norminette/norminette.rb
	OS			=	$(PINK)Windows
else
	OS			=	$(shell uname -s)
	ifeq ($(OS), Darwin)
		MINILIBX	=	-framework OpenGL -framework AppKit -framework OpenAL
		LIBS		=	-L libft -L mlx
		LDLIBS		=	-lm -lmlx -lft
		DLIBS		=	libft/libft.a
		NORMINETTE	=	norminettev2
		OS			=	$(END)$(PINK)Mac OS$(END)
	else
		ifeq ($(OS), Linux)
			LIBS		=	-L libft -L mlx
			LDLIBS		=	-lm -lmlx -lft
			DLIBS		=	libft/libft.a
			NORMINETTE	=	~/.norminette/norminette.rb
			OS			=	$(END)$(PINK)Linux$(END)
		else
			OS			=	$(END)$(RED)$(BOLD)This OS is not supported$(END)
		endif
	endif
endif

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror $(LDFLAGS)
CPPFLAGS	=	-I $(INC_PATH) -I libft/$(INC_PATH) -I mlx

ERASE		=	\033[2K\r
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLD		=	\033[1m
UNDER		=	\033[4m
SUR			=	\033[7m
END			=	\033[0m

.PHONY: all compilation clean fclean re norm

all: compilation $(NAME)
ifeq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@printf "\n$(OS)\n\n"
	@printf "$(BLUE)> $(NAME) : $(RED)Project fail !$(END)\n"
else
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"
endif

compilation:
	@make -C libft

$(NAME): $(OBJ)
ifneq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@$(CC) $(CFLAGS) $(LIBS) $(MINILIBX) $(LDLIBS) $^ -o $@
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"
endif

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC) $(DLIBS)
	@mkdir -p $(OBJ_PATH) $(addprefix $(OBJ_PATH)/,$(DIR))
ifeq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@touch $@
else
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"
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

norm:
ifeq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@printf "\n$(BOLD)$(RED)Norminette is not supported$(END)\n\n"
else
	@make -C libft norm
	$(NORMINETTE) $(INC_PATH) $(SRC_PATH)
endif
