/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/17 11:45:46 by omimouni         ###   ########.fr       */
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

void		mrt_has_alphabet(char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != 0)
	{
		if (s[i] < '0' || s[i] > '9')
			mrt_trigger_error(17);
		i++;
	}
}

void		mrt_parse_resolution(char **key)
{
	double	width;
	double	height;

	if (g_conf->res_parsed)
		mrt_trigger_error(18);
	mrt_has_alphabet(key[1]);
	mrt_has_alphabet(key[2]);
	if ((key[1] == NULL) || (key[2] == NULL) || (key[3] != NULL))
		mrt_trigger_error(15);
	width = ft_atoi(key[1]);
	height = ft_atoi(key[2]);
	width = ft_clamp_int(width, 0, 2600);
	height = ft_clamp_int(height, 0, 1600);
	if (width < 0 || height < 0)
		mrt_trigger_error(16);
	if (width == 0)
		mrt_trigger_error(4);
	if (height == 0)
		mrt_trigger_error(5);
	if (ft_strchr(key[1], '.') || ft_strchr(key[2], '.'))
		mrt_trigger_error(6);
	g_conf->width = width;
	g_conf->height = height;
	g_conf->res_parsed = 1;
}

void	mrt_parse_ambient(char **key)
{
	double	i;
	t_color	c;

	if (g_conf->am_parsed)
		mrt_trigger_error(19);
	i =	ft_parsefloat(key[1]);
	i > 1 || i < 0 ? mrt_trigger_error(7) : NULL;
	c = mrt_parse_color_valid(key[2]);
	g_conf->ambient_light = ambiant_light_new(i, c.r, c.g, c.b);
	g_conf->al_calculated = color_multi(g_conf->ambient_light.color,
		powf(g_conf->ambient_light.intensity, 2));
	g_conf->am_parsed = 1;
}

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
