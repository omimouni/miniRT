/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:10:41 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 03:56:05 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


// TODO: normalize target vector
t_cam	*cam_init(t_pt3f *orig, t_vec3f *tar, int fov)
{
	t_cam	*tmp;

	tmp = malloc(sizeof(t_cam));
	tmp->origin = orig;
	tmp->target = tar;
	tmp->fov = fov;
	tmp->r = 700.0f / 500.0f;
	return (tmp);
}

double	cam_pixel_x(int x, t_cam *cam, t_conf *conf)
{
	double px;

	px = x;
	return (px);
}

void	cam_free(t_cam *cam)
{
	free(cam->origin);
	free(cam->target);
	free(cam);
}