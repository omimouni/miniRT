/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:48:22 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/30 14:53:19 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

t_camera	*camera_new_(t_point3 origin, t_vector3 target, int fov)
{
	t_camera	*tmp;

	tmp = malloc(sizeof(t_camera));
	tmp->origin = origin;
	tmp->target = target;
	tmp->fov = fov;
	tmp->aspect_ratio = g_conf->width / g_conf->height;
	tmp->normal = vec3_normalize(tmp->target);
	tmp->scene_h = atan(fov);
	tmp->scene_w = tmp->aspect_ratio * tmp->scene_h;
	tmp->upguide = vec3_new(0, 1, 0);
	tmp->right = vec3_cross(tmp->normal, tmp->upguide);
	tmp->up = vec3_cross(tmp->right, tmp->normal);
	tmp->right = vec3_normalize(tmp->right);
	tmp->up = vec3_normalize(tmp->up);
	return (tmp);
}

double		camera_position_x(size_t px)
{
	return (((2 * px) / (double)(g_conf->width)) - 1);
}

double		camera_position_y(size_t py)
{
	return (((2 * py) / (double)(g_conf->height)) - 1);
}
