/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:49:33 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 12:36:23 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_parse_sphere(char **key)
{
	t_point3	center;
	double		diameter;
	t_color		color;

	if ((key[1] == NULL) || (key[2] == NULL) || (key[3] == NULL)
		|| (key[4] != NULL))
		mrt_trigger_error(15);
	center = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	mrt_is_double(key[2], 0);
	diameter = ft_parsefloat(key[2]);
	color = mrt_parse_color_valid(key[3]);
	(diameter <= 0) ? mrt_trigger_error(26) : NULL;
	g_conf->objs = ft_glist_add(g_conf->objs, 
		sphere_new(center, diameter, color));
}
