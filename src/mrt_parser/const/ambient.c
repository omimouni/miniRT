/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:36:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 16:39:48 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

void	mrt_parse_ambient(char **key)
{
	double	i;
	t_color	c;

	if (g_conf->am_parsed)
		mrt_trigger_error(19);
	if ((key[1] == NULL) || (key[2] == NULL) || (key[3] != NULL))
		mrt_trigger_error(15);
	mrt_is_double(key[1], 0);
	i = ft_parsefloat(key[1]);
	(i > 1 || i < 0) ? mrt_trigger_error(7) : NULL;
	c = mrt_parse_color_valid(key[2]);
	g_conf->ambient_light = ambiant_light_new(i, c.r, c.g, c.b);
	g_conf->al_calculated = color_multi(g_conf->ambient_light.color,
		powf(g_conf->ambient_light.intensity, 2));
	g_conf->am_parsed = 1;
}
