# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 14:43:31 by qpupier           #+#    #+#              #
#    Updated: 2021/02/24 21:14:27 by qpupier          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INC_PATH = includes
SRC_PATH = sources
OBJ_PATH = .objects
SRC_SUP = 	display												\
			math												\
			math/cplx											\
			math/geometry										\
			math/line											\
			math/matrix											\
			math/real											\
			math/sys											\
			math/vec											\
			memory												\
			str
SRC_NAME = 	display/ft_putchar_fd.c 							\
			display/ft_putchar.c 								\
			display/ft_putendl_fd.c 							\
			display/ft_putendl.c 								\
			display/ft_putnbr_fd.c 								\
			display/ft_putnbr.c 								\
			display/ft_putstr_fd.c 								\
			display/ft_putstr.c 								\
			math/cplx/cplx_add.c 								\
			math/cplx/cplx_average.c 							\
			math/cplx/cplx_cos.c 								\
			math/cplx/cplx_cosh.c 								\
			math/cplx/cplx_discriminant.c 						\
			math/cplx/cplx_div.c 								\
			math/cplx/cplx_equ.c 								\
			math/cplx/cplx_exp.c 								\
			math/cplx/cplx_ln.c 								\
			math/cplx/cplx_modul.c 								\
			math/cplx/cplx_modul_2.c 							\
			math/cplx/cplx_mult.c 								\
			math/cplx/cplx_pow.c 								\
			math/cplx/cplx_remove.c 							\
			math/cplx/cplx_sin.c 								\
			math/cplx/cplx_sinh.c 								\
			math/cplx/cplx_swap.c 								\
			math/cplx/cplx_to_real.c 							\
			math/cplx/cplx_turn.c 								\
			math/cplx/cplx_make.c 								\
			math/cplx/ft_make_real.c 							\
			math/cplx/ft_real_to_cplx.c 						\
			math/geometry/create_2d_line_point_vec.c 			\
			math/geometry/create_2d_line_points.c 				\
			math/geometry/create_2d_ray.c 						\
			math/geometry/inter_2d_line_line.c 					\
			math/geometry/inter_2d_line_seg.c 					\
			math/geometry/inter_2d_ray_seg.c 					\
			math/geometry/point_2d_line_in_seg.c 				\
			math/geometry/point_line_in_seg.c 					\
			math/geometry/proj_point.c 							\
			math/line/line_check.c 								\
			math/line/line_create.c 							\
			math/line/line_equal.c 								\
			math/line/inter_ray_seg.c 							\
			math/line/line_init.c 								\
			math/line/line_inter_line.c 						\
			math/line/line_inter_seg.c 							\
			math/line/line_parallel_line_point.c 				\
			math/line/line_perpendicular_line_point_plane.c 	\
			math/line/line_point.c 								\
			math/line/line_vec_dir.c 							\
			math/line/inter_line_plane.c 						\
			math/line/inter_seg_plane.c 						\
			math/matrix/matrix_mult_matrix.c 					\
			math/matrix/matrix_mult_vec.c 						\
			math/matrix/matrix_rotation.c 						\
			math/real/op_real.c 								\
			math/real/real_norm.c 								\
			math/real/real_normalize.c 							\
			math/real/real_oriented_angle.c 					\
			math/real/real_scale_product.c 						\
			math/real/real_turn.c 								\
			math/real/real_arraycpy.c 							\
			math/sys/sys_solve_1equ_1var_deg1.c 				\
			math/sys/sys_solve_2equ_2var_deg1.c 				\
			math/sys/sys_solve_1equ_1var_deg2.c					\
			math/vec/vec_add.c 									\
			math/vec/vec_array_cpy.c 							\
			math/vec/vec_check.c 								\
			math/vec/vec_null.c 								\
			math/vec/vec_normalize.c 							\
			math/vec/vec_collinears.c 							\
			math/vec/vec_create.c 								\
			math/vec/vec_equal.c 								\
			math/vec/vec_mult.c 								\
			math/vec/vec_move.c 								\
			math/vec/vec_norm.c 								\
			math/vec/vec_product.c 								\
			math/vec/vec_sub.c 									\
			math/vec/vec_extract.c 								\
			math/vec/vec_rot.c 									\
			math/ft_abs.c 										\
			math/ft_average.c 									\
			math/ft_deg_to_rad.c 								\
			math/ft_rad_to_deg.c 								\
			math/clamp.c 										\
			math/ft_digit_abs.c 								\
			math/ft_digit_hex_to_int.c 							\
			math/ft_max.c 										\
			math/ft_min.c 										\
			math/ft_mod.c 										\
			math/ft_pow.c 										\
			math/ft_sq.c 										\
			math/ft_sqrt.c 										\
			math/float_cmp.c 									\
			memory/ft_memalloc.c 								\
			memory/ft_memccpy.c 								\
			memory/ft_memchr.c 									\
			memory/ft_memcmp.c 									\
			memory/ft_memcpy.c 									\
			memory/ft_memdel.c 									\
			memory/ft_memmove.c 								\
			memory/ft_memset.c 									\
			str/ft_stractrim.c 									\
			str/ft_strcat.c 									\
			str/ft_strchr.c 									\
			str/ft_strclr.c 									\
			str/ft_strcmp.c 									\
			str/ft_strcpy.c 									\
			str/ft_strcspn.c 									\
			str/ft_strctrim.c 									\
			str/ft_strdel.c 									\
			str/ft_strdup.c 									\
			str/ft_strequ.c 									\
			str/ft_striter.c 									\
			str/ft_str_getaocc.c 								\
			str/ft_count_dstr.c 								\
			str/ft_striteri.c 									\
			str/ft_strjoin.c 									\
			str/ft_strlcat.c 									\
			str/ft_strlen.c 									\
			str/ft_strlen_words.c 								\
			str/ft_strmap.c 									\
			str/ft_strmap_display.c 							\
			str/ft_strmapi.c 									\
			str/ft_strncat.c 									\
			str/ft_strncdelete.c 								\
			str/ft_strncmp.c 									\
			str/ft_strncpy.c 									\
			str/ft_strnequ.c 									\
			str/ft_strnew.c 									\
			str/ft_strnstr.c 									\
			str/ft_strrchr.c 									\
			str/ft_strsearch.c 									\
			str/ft_strsplit.c 									\
			str/ft_strstr.c 									\
			str/ft_str_isnumber.c 								\
			str/ft_strsub.c 									\
			str/ft_strtrim.c 									\
			str/ft_strtrimsplit.c 								\
			get_next_line.c 									\
			ft_atoi.c 											\
			ft_atof.c 											\
			ft_atoi_hexa.c 										\
			ft_bzero.c 											\
			ft_count_words.c 									\
			ft_error.c 											\
			ft_exit.c 											\
			ft_find.c 											\
			ft_ftoa.c 											\
			ft_intlen.c 										\
			ft_isalnum.c 										\
			ft_isalpha.c 										\
			ft_isascii.c 										\
			ft_isdigit.c 										\
			ft_isnumber.c 										\
			ft_isprint.c 										\
			ft_itoa.c 											\
			ft_occur.c 											\
			ft_splitdel.c 										\
			ft_swap.c 											\
			ft_fileexists.c 									\
			ft_tolower.c 										\
			ft_toupper.c 										\
			ft_realloc.c 										\
			ft_calloc.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = libft.h
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))
LDFLAGS = -O3 -ffast-math -march=native
LDLIBS = -lm
ifeq ($(OS), Windows_NT)
	NORMINETTE = ~/.norminette/norminette.rb
	OS = $(PINK)Windows
else
	OS = $(shell uname -s)
	ifeq ($(OS), Darwin)
		NORMINETTE = norminette
		OS = $(END)$(PINK)Mac OS
	else
		ifeq ($(OS), Linux)
			NORMINETTE = ~/.norminette/norminette.rb
			OS = $(END)$(PINK)Linux
		else
			OS = $(RED)This OS is not supported
		endif
	endif
endif
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(LDFLAGS)
CPPFLAGS = -I $(INC_PATH)

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

.PHONY: all detected_OS clean fclean re norme

all: detected_OS $(NAME)
ifeq ($(OS), $(RED)This OS is not supported)
	@printf "$(BLUE)> libft : $(RED)Lib fail !$(END)\n"
else
	@printf "$(BLUE)> libft : $(YELLOW)Lib ready !$(END)\n"
endif

detected_OS:
	@printf "$(BOLD)$(GREY)Detected OS : $(OS)$(END)\n"

$(NAME): $(OBJ)
ifneq ($(OS), $(RED)This OS is not supported)
	@ar -rc $@ $^
	@ranlib $@
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n"
endif

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH) $(addprefix $(OBJ_PATH)/,$(SRC_SUP))
ifeq ($(OS), $(RED)This OS is not supported)
	@touch $@
else
	@printf "$(ERASE)$(YELLOW)$(BOLD)[COMPILE] $(END) $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
endif

clean:
	@rm -rf $(OBJ_PATH)
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)libft/$(OBJ_PATH)$(END)\n"

fclean: clean
	@rm -rf $(NAME) $(NAME).exe
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)libft/$(NAME)$(END)\n"

re: fclean all

norme:
ifeq ($(OS), $(RED)This OS is not supported)
	@printf "Norminette is not supported\n"
else
	$(NORMINETTE) $(INC_PATH) $(SRC_PATH)
endif
