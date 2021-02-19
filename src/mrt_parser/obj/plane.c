/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:49:50 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 15:22:02 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_parse_plane(char **key)
{
	t_point3	point;
	t_vector3	normal;
	t_color		color;

	if ((key[1] == NULL) || (key[2] == NULL) || (key[3] == NULL)
		|| (key[4] != NULL))
		mrt_trigger_error(15);
	point = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	normal = mrt_parse_vec3(key[2], MRT_VEC3_STANDARD);
	normal = vec3_normalize(normal);
	color = mrt_parse_color_valid(key[3]);
	g_conf->objs = ft_glist_add(g_conf->objs, 
		plane_new(point, normal, color));
}
