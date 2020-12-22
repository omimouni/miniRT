/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:10:41 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 05:35:37 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*cam_init(t_pt3f *orig, t_vec3f *tar, int fov, t_conf *conf)
{
	t_cam	*tmp;

	tmp = malloc(sizeof(t_cam));
	tmp->origin = orig;
	tmp->forward = tar;
	tmp->fov = fov;
	tmp->r = (float)conf->width / (float)conf->height;
	return (tmp);
}

double	cam_pixel_x(int px, t_cam *cam, t_conf *conf)
{
	return (((2.0f*(px)) / (double)conf->width) - 1.0f);
}

double	cam_pixel_y(int py, t_cam *cam, t_conf *conf)
{
	return (((2.0f*(py)) / (double)conf->height) - 1.0f);
}

void	cam_free(t_cam *cam)
{
	free(cam->origin);
	free(cam->forward);
	free(cam);
}