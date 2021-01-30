/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:48:22 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/30 11:05:13 by omimouni         ###   ########.fr       */
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

	// @todo: calculate U/R
	tmp->fov = fov;
	tmp->aspect_ratio = g_conf->width / g_conf->height;
	tmp->normal = vec3_normalize(tmp->target);
	tmp->scene_h = atan(fov);
	tmp->scene_w = tmp->aspect_ratio * tmp->scene_h;
	return (tmp);
}
