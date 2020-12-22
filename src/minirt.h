/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 04:19:04 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 05:29:26 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WINDOW_TITLE "miniRT"
# define M_PI 3.14159265

# include <stdio.h>
# include <mlx.h>
# include "utils/utils.h"


typedef	struct	s_conf {
	void		*mlx;
	void		*win;
	size_t		height;
	size_t		width;
}				t_conf;

typedef struct	s_cam {
	t_pt3f		*origin;
	t_vec3f		*forward;
	t_vec3f		upguide;
	t_vec3f		up;
	t_vec3f		right;
	int			fov;
	double		r;
}				t_cam;

void			parser(int argc, char **argv, t_conf *conf);
void			win_init(t_conf *conf);
void			win_hook(t_conf *conf);
void			render(t_conf *conf);
t_cam			*cam_init(t_pt3f *orig, t_vec3f *tar, int fov, t_conf *conf);
double			cam_pixel_x(int px, t_cam *cam, t_conf *conf);
double			cam_pixel_y(int py, t_cam *cam, t_conf *conf);
void			cam_free(t_cam *cam);
#endif
