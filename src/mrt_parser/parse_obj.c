/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:53:42 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 19:05:55 by omimouni         ###   ########.fr       */
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

void	mrt_parse_plane(char **key)
{
	t_point3	point;
	t_vector3	normal;
	t_color		color;

	point = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	normal = mrt_parse_vec3(key[2], MRT_VEC3_NORMALIZED);
	color = mrt_parse_color_valid(key[3]);

	g_conf->objs = ft_glist_add(g_conf->objs, 
		plane_new(point, normal, color));
}

void	mrt_parse_cylinder(char **key)
{
	t_point3	base;
	t_vector3	normal;
	double		d[2];
	t_color		color;

	printf("M here");

	base = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	normal = mrt_parse_vec3(key[2], MRT_VEC3_NORMALIZED);
	d[0] = ft_parsefloat(key[3]);
	d[1] = ft_parsefloat(key[4]);
	color = mrt_parse_color_valid(key[5]);
	
	g_conf->objs = ft_glist_add(g_conf->objs, 
		cylinder_new(base, normal, color, d));
}