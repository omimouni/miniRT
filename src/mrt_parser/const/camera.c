/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:05:26 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 12:09:33 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

void	mrt_parse_camera(char **key)
{
	t_point3	pt;
	t_vector3	orient;
	double		fov;

	if ((key[1] == NULL) || (key[2] == NULL) ||(key[3] == NULL)
		|| (key[4] != NULL))
		mrt_trigger_error(13);
	pt = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	orient = mrt_parse_vec3(key[2], MRT_VEC3_STANDARD);
	orient = vec3_normalize(orient);
	mrt_is_double(key[3], 0);
	fov = ft_parsefloat(key[3]);
	(fov < 0 || fov > 180) ? mrt_trigger_error(24) : NULL;
	g_conf->cameras = ft_glist_add(g_conf->cameras, 
						camera_new_(pt, orient, fov));
}
