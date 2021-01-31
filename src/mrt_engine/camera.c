/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:48:22 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/31 17:46:02 by omimouni         ###   ########.fr       */
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
	tmp->fov = (double)fov * M_PI / 180;
	tmp->aspect_ratio = (double)g_conf->width / (double)g_conf->height;
	tmp->normal = vec3_normalize(tmp->target);
	tmp->scene_h = atan(tmp->fov);
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
	return (((double)(2 * (px)) / (double)(g_conf->width)) - 1);
}

double		camera_position_y(size_t py)
{
	return (((double)(2 * (py)) / (double)(g_conf->height)) - 1);
}
