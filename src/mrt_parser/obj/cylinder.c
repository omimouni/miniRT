/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:52:14 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 12:51:17 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_parse_cylinder(char **key)
{
	t_point3	base;
	t_vector3	normal;
	double		d[2];
	t_color		color;

	if ((key[1] == NULL) || (key[2] == NULL) || (key[3] == NULL)
		|| (key[4] == NULL) || (key[5] == NULL) || (key[6] != NULL))
		mrt_trigger_error(15);
	base = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	normal = mrt_parse_vec3(key[2], MRT_VEC3_STANDARD);
	mrt_is_double(key[3], 0);
	mrt_is_double(key[3], 0);
	d[0] = ft_parsefloat(key[3]);
	d[1] = ft_parsefloat(key[4]);
	if (d[0] <= 0 || d[1] <= 0)
		mrt_trigger_error(27);
	color = mrt_parse_color_valid(key[5]);
	g_conf->objs = ft_glist_add(g_conf->objs, 
		cylinder_new(base, normal, color, d));
}