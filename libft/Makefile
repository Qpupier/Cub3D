# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 11:56:39 by qpupier           #+#    #+#              #
#    Updated: 2021/02/09 16:08:47 by qpupier          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC_PATH	=	sources
OBJ_PATH	=	.objects
INC_PATH	=	includes
SRC_SUP		=	display 		\
				maths 			\
				maths/line 		\
				maths/cplx 		\
				maths/geometry 	\
				maths/matrix 	\
				maths/real 		\
				maths/vec 		\
				maths/sys 		\
				memory 			\
				mlx 			\
				mlx/colors 		\
				mlx/line 		\
				str
SRC_NAME	=	display/ft_putchar_fd.c 							\
				display/ft_putchar.c 								\
				display/ft_putendl_fd.c 							\
				display/ft_putendl.c 								\
				display/ft_putnbr_fd.c 								\
				display/ft_putnbr.c 								\
				display/ft_putstr_fd.c 								\
				display/ft_putstr.c 								\
				maths/cplx/cplx_add.c 								\
				maths/cplx/cplx_average.c 							\
				maths/cplx/cplx_cos.c 								\
				maths/cplx/cplx_cosh.c 								\
				maths/cplx/cplx_discriminant.c 						\
				maths/cplx/cplx_div.c 								\
				maths/cplx/cplx_equ.c 								\
				maths/cplx/cplx_exp.c 								\
				maths/cplx/cplx_ln.c 								\
				maths/cplx/cplx_modul.c 							\
				maths/cplx/cplx_modul_2.c 							\
				maths/cplx/cplx_mult.c 								\
				maths/cplx/cplx_pow.c 								\
				maths/cplx/cplx_remove.c 							\
				maths/cplx/cplx_sin.c 								\
				maths/cplx/cplx_sinh.c 								\
				maths/cplx/cplx_swap.c 								\
				maths/cplx/cplx_to_real.c 							\
				maths/cplx/cplx_turn.c 								\
				maths/cplx/cplx_make.c 								\
				maths/cplx/ft_make_real.c 							\
				maths/cplx/ft_real_to_cplx.c 						\
				maths/geometry/create_2d_line_point_vec.c 			\
				maths/geometry/create_2d_line_points.c 				\
				maths/geometry/create_2d_ray.c 						\
				maths/geometry/inter_2d_line_line.c 				\
				maths/geometry/inter_2d_line_seg.c 					\
				maths/geometry/inter_2d_ray_seg.c 					\
				maths/geometry/point_2d_line_in_seg.c 				\
				maths/geometry/point_line_in_seg.c 					\
				maths/geometry/proj_point.c 						\
				maths/line/line_check.c 							\
				maths/line/line_create.c 							\
				maths/line/line_equal.c 							\
				maths/line/line_half_inter_seg.c 					\
				maths/line/line_init.c 								\
				maths/line/line_inter_line.c 						\
				maths/line/line_inter_seg.c 						\
				maths/line/line_parallel_line_point.c 				\
				maths/line/line_perpendicular_line_point_plane.c 	\
				maths/line/line_point.c 							\
				maths/line/line_vec_dir.c 							\
				maths/line/inter_line_plane.c 						\
				maths/line/inter_seg_plane.c 						\
				maths/matrix/matrix_mult_matrix.c 					\
				maths/matrix/matrix_mult_vec.c 						\
				maths/matrix/matrix_rotation.c 						\
				maths/real/op_real.c 								\
				maths/real/real_norm.c 								\
				maths/real/real_normalize.c 						\
				maths/real/real_oriented_angle.c 					\
				maths/real/real_scale_product.c 					\
				maths/real/real_turn.c 								\
				maths/real/real_arraycpy.c 							\
				maths/sys/sys_solve_1equ_1var_deg1.c 				\
				maths/sys/sys_solve_2equ_2var_deg1.c 				\
				maths/vec/vec_add.c 								\
				maths/vec/vec_array_cpy.c 							\
				maths/vec/vec_check.c 								\
				maths/vec/vec_null.c 								\
				maths/vec/vec_normalize.c 							\
				maths/vec/vec_collinears.c 							\
				maths/vec/vec_create.c 								\
				maths/vec/vec_equal.c 								\
				maths/vec/vec_mult.c 								\
				maths/vec/vec_move.c 								\
				maths/vec/vec_norm.c 								\
				maths/vec/vec_product.c 							\
				maths/vec/vec_sub.c 								\
				maths/vec/vec_extract.c 							\
				maths/vec/vec_rot.c 								\
				maths/ft_abs.c 										\
				maths/ft_average.c 									\
				maths/ft_deg_to_rad.c 								\
				maths/clamp.c 										\
				maths/ft_digit_abs.c 								\
				maths/ft_digit_hex_to_int.c 						\
				maths/ft_max.c 										\
				maths/ft_min.c 										\
				maths/ft_mod.c 										\
				maths/ft_pow.c 										\
				maths/ft_sq.c 										\
				maths/ft_sqrt.c 									\
				maths/float_cmp.c 									\
				memory/ft_memalloc.c 								\
				memory/ft_memccpy.c 								\
				memory/ft_memchr.c 									\
				memory/ft_memcmp.c 									\
				memory/ft_memcpy.c 									\
				memory/ft_memdel.c 									\
				memory/ft_memmove.c 								\
				memory/ft_memset.c 									\
				mlx/colors/ft_color_average.c 						\
				mlx/colors/ft_color_hex_to_rgb.c 					\
				mlx/colors/ft_color_int_to_rgb.c 					\
				mlx/colors/ft_color_convert.c 						\
				mlx/colors/ft_color_rgb_random.c 					\
				mlx/colors/ft_color_rgb_to_hex.c 					\
				mlx/colors/ft_color_rgb_to_int.c 					\
				mlx/colors/ft_hex_color_complete.c 					\
				mlx/line/ft_line.c 									\
				mlx/line/ft_line_horiz.c 							\
				mlx/line/ft_line_straight.c 						\
				mlx/line/ft_line_straight_horiz.c 					\
				mlx/line/ft_line_straight_vert.c 					\
				mlx/line/ft_line_vert.c 							\
				mlx/file_to_img.c 									\
				mlx/ft_create_img.c 								\
				mlx/ft_img_dark.c 									\
				mlx/ft_pixel_put.c 									\
				mlx/ft_get_pixel.c 									\
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
				str/ft_strsplit.c 									\
				str/ft_strstr.c 									\
				str/ft_str_isnumber.c 								\
				str/ft_strsub.c 									\
				str/ft_strtrim.c 									\
				str/ft_strtrimsplit.c 								\
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
				ft_calloc.c 										\
				get_next_line.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
INC_NAME	=	libft.h 	\
				get_next_line.h
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC			=	$(addprefix $(INC_PATH)/,$(INC_NAME))
CC			=	gcc
LDFLAGS		=	-O3 -march=native -flto -ffast-math
CFLAGS		=	-Wall -Wextra -Werror $(LDFLAGS)
CPPFLAGS	=	-I $(INC_PATH)

ifeq ($(OS), Windows_NT)
	NORMINETTE = ~/.norminette/norminette.rb
	OS = $(PINK)Windows
else
	OS = $(shell uname -s)
	ifeq ($(OS), Darwin)
		NORMINETTE = norminettev2
		OS = $(END)$(PINK)Mac OS$(END)
	else
		ifeq ($(OS), Linux)
			NORMINETTE = ~/.norminette/norminette.rb
			OS = $(END)$(PINK)Linux$(END)
		else
			OS = $(END)$(RED)$(BOLD)This OS is not supported$(END)
		endif
	endif
endif

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

.PHONY: all, mlx, clean, fclean, re, norm

all: mlx $(NAME)
ifeq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@printf "\n$(OS)\n\n"
	@printf "$(BLUE)> $(NAME) : $(RED)Libft fail !$(END)\n"
else
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Libft ready !$(END)\n"
endif

$(NAME): $(OBJ)
ifneq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@ar rc $@ $^
	@ranlib $@
	@printf "$(ERASE)$(BLUE)> Libft : $(GREEN)Success !$(END)\n"
endif

mlx:
ifneq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@make -C ../mlx
endif

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c ../libmlx.dylib $(INC)
	@mkdir -p $(OBJ_PATH) $(addprefix $(OBJ_PATH)/,$(SRC_SUP))
ifeq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@touch $@
else
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"
endif

clean:
	@rm -rf $(OBJ_PATH)
	@printf "$(BLUE)> Deleted : $(RED)libft/$(OBJ_PATH)$(END)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

norm:
ifeq ($(OS), $(END)$(RED)$(BOLD)This OS is not supported$(END))
	@printf "\n$(BOLD)$(RED)Norminette is not supported$(END)\n\n"
else
	$(NORMINETTE) $(INC_PATH) $(SRC_PATH)
endif
