/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 04:19:04 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 02:11:57 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WINDOW_TITLE "miniRT"

# include <stdio.h>
# include <mlx.h>
# include "utils/utils.h"


typedef	struct	s_conf {
	void		*mlx;
	void		*win;
}				t_conf;

typedef struct	s_cam {
	t_pt3f		*origin;
	t_vec3f		*target;
	int			fov;
	double		r;
}				t_cam;

void			parser(int argc, char **argv, t_conf *conf);
void			win_init(t_conf *conf);
void			win_hook(t_conf *conf);
void			render(t_conf *conf);
t_cam			*cam_init(t_pt3f *orig, t_vec3f *tar, int fov);
void			cam_free(t_cam *cam);
#endif
