/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:49:33 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 11:50:03 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_parse_sphere(char **key)
{
	t_point3	center;
	double		diameter;
	t_color		color;

	center = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	diameter = ft_parsefloat(key[2]);
	color = mrt_parse_color_valid(key[3]);

	g_conf->objs = ft_glist_add(g_conf->objs, 
		sphere_new(center, diameter, color));
}
