/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 11:36:10 by omimouni         ###   ########.fr       */
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

void		mrt_isdigit(char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	
	while (s[i] != 0)
	{
		if (!ft_isdigit(s[i]))
			mrt_trigger_error(17);
		if (s[i] == '.')
			if (i - 1 != 0 && !ft_isdigit(s[i + 1]))
				mrt_trigger_error(17);
		i++;
	}
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
