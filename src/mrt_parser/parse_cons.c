/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/10 08:18:07 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

/*
** Parsing 
** -----
** TODO: Add Screen max size
** FIXME: memory Leaks
*/

void		mrt_parse_resolution(char **key)
{
	double	width;
	double	height;

	width = ft_atoi(key[1]);
	height = ft_atoi(key[2]);
	if (width == 0)
		mrt_trigger_error(4);
	if (height == 0)
		mrt_trigger_error(5);
	if (ft_strchr(key[1], '.') || ft_strchr(key[2], '.'))
		mrt_trigger_error(6);
	g_conf->width = width;
	g_conf->height = height;
}

void	mrt_parse_ambient(char **key)
{
	double	i;
	t_color	c;

	i =	ft_parsefloat(key[1]);
	i > 1 || i < 0 ? mrt_trigger_error(7) : NULL;
	c = mrt_parse_color_valid(key[2]);
	g_conf->ambient_light = ambiant_light_new(i, c.r, c.g, c.b);
	g_conf->al_calculated = color_multi(g_conf->ambient_light.color,
		powf(g_conf->ambient_light.intensity, 2));
}

void	mrt_parse_camera(char **key)
{
	t_point3	pt;
	t_vector3	orient;
	double		fov;

	if (ISN(key[1]) || ISN(key[2]) ||ISN(key[3]) || !ISN(key[4]))
		mrt_trigger_error(13);
	pt = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	orient = mrt_parse_vec3(key[2], MRT_VEC3_NORMALIZED);
	fov = ft_parsefloat(key[3]);
	g_conf->cameras = ft_glist_add(g_conf->cameras, 
						camera_new_(pt, orient, fov));
}

void	mrt_parse_light(char **key)
{
	t_point3	pt;
	double		val;
	t_color		color;

	pt = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	val = ft_parsefloat(key[2]);
	color = mrt_parse_color_valid(key[3]);
	
	g_conf->lights = ft_glist_add(g_conf->lights, 
	light_new(pt, val, color));
}
