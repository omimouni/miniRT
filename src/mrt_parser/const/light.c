/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:29:12 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 16:41:23 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

void	mrt_parse_light(char **key)
{
	t_point3	pt;
	double		val;
	t_color		color;

	if ((key[1] == NULL) || (key[2] == NULL) || (key[3] == NULL)
		|| (key[4] != NULL))
		mrt_trigger_error(15);
	pt = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	mrt_is_double(key[2], 0);
	val = ft_parsefloat(key[2]);
	(val > 1 || val < 0) ? mrt_trigger_error(25) : NULL;
	color = mrt_parse_color_valid(key[3]);
	g_conf->lights = ft_glist_add(g_conf->lights,
	light_new(pt, val, color));
}
