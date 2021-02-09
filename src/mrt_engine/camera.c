/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:48:22 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 15:53:15 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

/*
** Camera model
*/

t_camera	*camera_new_(t_point3 origin, t_vector3 target, int fov)
{
	t_camera	*tmp;

	tmp = malloc(sizeof(t_camera));
	tmp->origin = origin;
	tmp->target = target;
	tmp->fov = (double)fov * M_PI / 180;
	return (tmp);
}

void		camera_calc(t_camera *camera)
{
	camera->aspect_ratio = (double)g_conf->width / (double)g_conf->height;
	camera->normal = vec3_normalize(camera->target);
	camera->scene_h = atan(camera->fov / 2);
	camera->scene_w = camera->aspect_ratio * camera->scene_h;
	camera->upguide = vec3_new(0, 1, (camera->normal.y));
	camera->upguide = vec3_normalize(camera->upguide);
	camera->right = vec3_cross(camera->normal, camera->upguide);
	camera->right = vec3_normalize(camera->right);
	camera->up = vec3_cross(camera->normal, camera->right);
	camera->up = vec3_normalize(camera->up);
}

double		camera_position_x(size_t px)
{
	return (((double)(2 * (px)) / (double)(g_conf->width)) - 1);
}

double		camera_position_y(size_t py)
{
	return (((double)(2 * (py)) / (double)(g_conf->height)) - 1);
}
