/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 04:19:04 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/20 02:45:21 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WINDOW_TITLE "miniRT"
# include "utils/utils.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef	struct	s_conf {
	void		*mlx;
	void		*win;
}				t_conf;

typedef struct	s_cam {
	t_pt3f		*origin;
	t_vec3f		*target;
	int			fov;
}				t_cam;

void			parser(int argc, char **argv, t_conf *conf);
void			win_init(t_conf *conf);
void			win_hook(t_conf *conf);
void			render(t_conf *conf);
#endif