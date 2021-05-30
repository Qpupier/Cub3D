/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:43:13 by qpupier           #+#    #+#             */
/*   Updated: 2021/05/30 16:54:40 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void				calc(t_param *p);
void				events(t_param *p);
void				free_all(t_param *p);
void				free_fd(t_param *p, const char *error);
void				free_image(t_param *p, const char *error, int one, \
		void *img_ptr);
void				free_lst_map(t_parsing *map);
void				free_map(t_param *p);
void				free_one(t_param *p, void *ptr, int one);
void				free_rays_theta(t_param *p);
void				free_window(t_param *p, const char *error, int one, \
		void *win_ptr);
void				ft_error_free(t_param *p, const char *error);
void				ft_error_free_array(t_param *p, int theta, \
		const char *error);
void				ft_newton(t_param *p);
void				init(t_param *p);
void				init_trigo(t_param *p);
void				init_parameters(t_param *p);
void				init_rays_theta(t_param *p);
void				init_strings_fps(char *strings_fps[]);
void				jump(t_param *p, t_move_buttons card);
void				move(t_param *p, t_move_buttons card);
void				parsing(t_param *p);
void				parsing_array_error(t_param *p, t_parsing *map, int nb, \
		const char *error);
void				parsing_error(t_param *p, const char *error);
void				parsing_line_error(t_param *p, char *line, \
		const char *error);
void				parsing_line_error_tmp(t_param *p, char *line, char *tmp, \
		const char *error);
void				parsing_line_error_map(t_param *p, char *line, \
		t_parsing *map, const char *error);
void				parsing_lst_error_map(t_param *p, t_parsing *map, \
		const char *error);
void				parsing_c(t_param *p, char *line, int i);
void				parsing_ea(t_param *p, char *line, int i);
void				parsing_f(t_param *p, char *line, int i);
void				parsing_no(t_param *p, char *line, int i);
void				parsing_r(t_param *p, char *line, int i);
void				parsing_s(t_param *p, char *line, int i);
void				parsing_so(t_param *p, char *line, int i);
void				parsing_we(t_param *p, char *line, int i);
void				set_gravity(t_param *p);
void				verif_defines(void);
void				verif_map(t_param *p, t_parsing *map);
void				verif_parameters(t_param *p);
t_parsing			*parsing_line_map(t_param *p, char *line);
t_vec				vec_rot_x_pre(t_param *p, t_vec v, int angle);
t_vec				vec_rot_z_pre(t_param *p, t_vec v, int angle);
unsigned short int	inter_line_plane_x(t_line l, float d, t_vec *result, \
		float *t);
unsigned short int	inter_line_plane_y(t_line l, float d, t_vec *result, \
		float *t);
unsigned short int	select_texture(char *tmp, int size);
unsigned int		parsing_rgb(t_param *p, char *line);
unsigned int		ray_casting(t_param *p, t_vec ray);
int					algo(t_param *p);
int					key_press(int key, t_param *p);
int					key_release(int key, t_param *p);
int					parsing_parameters(t_param *p, char *line);
int					win_exit(t_param *p);
float				intersec_plane_c(t_param *p, t_line line, float *r_w, \
		float *r_h);
float				intersec_planes_e(t_param *p, t_line line, float *r_w, \
		float *r_h);
float				intersec_plane_f(t_param *p, t_line line, float *r_w, \
		float *r_h);
float				intersec_planes_n(t_param *p, t_line line, float *r_w, \
		float *r_h);
float				intersec_planes_s(t_param *p, t_line line, float *r_w, \
		float *r_h);
float				intersec_planes_w(t_param *p, t_line line, float *r_w, \
		float *r_h);

#endif
