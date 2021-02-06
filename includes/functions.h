/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:43:13 by qpupier           #+#    #+#             */
/*   Updated: 2021/02/06 15:21:00 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

void	parsing(t_param *p);
void	parsing_line_error_tmp(t_param *p, char *line, char *tmp, 	\
		const char *error);
void	parsing_line_error(t_param *p, char *line, const char *error);
void	parsing_no(t_param *p, char *line, int i);
void	parsing_so(t_param *p, char *line, int i);
void	parsing_we(t_param *p, char *line, int i);
void	parsing_ea(t_param *p, char *line, int i);
void	parsing_s(t_param *p, char *line, int i);
void	parsing_r(t_param *p, char *line, int i);
void	parsing_f(t_param *p, char *line, int i);
void	parsing_c(t_param *p, char *line, int i);
void		ft_error_free(t_param *p, const char *error);
void	free_image(t_param *p, const char *error, int one, void *img_ptr);
void	free_window(t_param *p, const char *error, int one, void *win_ptr);
void	free_fd(t_param *p, const char *error);
void	free_one(t_param *p, void *ptr, int one);
void		free_all(t_param *p);
int			parsing_parameters(t_param *p, char *line);
void		free_lst(t_parsing *map);
t_parsing	*parsing_line_map(t_param *p, char *line);
void	parsing_lst_error(t_param *p, t_parsing *map, const char *error);
void		verif_parameters(t_param *p);
void	parsing_error(t_param *p, const char *error);
void	parsing_array_error(t_param *p, t_parsing *map, int nb, 	\
		const char *error);

#endif
