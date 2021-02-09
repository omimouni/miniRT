/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 14:44:30 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define ISN(x) (x == NULL)

extern	t_conf	*g_conf;


t_color		mrt_parse_color_valid(char *color)
{
	char	**rgb;

	rgb = ft_split(color, ',');
	if (rgb[0] == NULL || rgb[1] == NULL ||
		rgb[2] == NULL || rgb[3] != NULL)
		mrt_trigger_error(8);
	(ft_strchr(rgb[0], '.') != NULL) ? mrt_trigger_error(9) : NULL; 
	(ft_strchr(rgb[1], '.') != NULL) ? mrt_trigger_error(9) : NULL; 
	(ft_strchr(rgb[2], '.') != NULL) ? mrt_trigger_error(9) : NULL;
	return (color_from_rgb(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2])));
}

/*
** Resolution Parse
** -----
** TODO: Add Screen max size
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

/*
** Parse ambient light
** -----
*/
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

/*
** Parse Camera
** -----
** FIXME: Memory leaks
*/

t_vector3	parse_vec3(char *cord, char type)
{
	char		**key;
	t_vector3	tmp;

	key = ft_split(cord, ',');
	if (key[0] == NULL || key[1] == NULL ||
		key[2] == NULL || key[3] != NULL)
		mrt_trigger_error(11);
	tmp.x = ft_parsefloat(key[0]);	
	tmp.y = ft_parsefloat(key[1]);	
	tmp.z = ft_parsefloat(key[2]);
	if (type == MRT_VEC3_NORMALIZED && vec3_length(tmp) != 1)
		mrt_trigger_error(12);
	return (tmp);
}

void	mrt_parse_camera(char **key)
{
	t_point3	pt;
	t_vector3	orient;
	double		fov;
	
	if (ISN(key[1]) || ISN(key[2]) || ISN(key[3]) || !ISN(key[4]))
		mrt_trigger_error(13);
	pt = parse_vec3(key[1], MRT_VEC3_STANDARD);
	orient = parse_vec3(key[2], MRT_VEC3_NORMALIZED);
	fov = ft_parsefloat(key[3]);
	g_conf->cameras = ft_glist_add(g_conf->cameras, 
						camera_new_(pt, orient, fov));
}