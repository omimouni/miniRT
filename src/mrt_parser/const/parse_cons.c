/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 12:05:44 by omimouni         ###   ########.fr       */
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
