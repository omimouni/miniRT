/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:55:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 16:41:44 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_init(void)
{
	g_conf = (t_conf *)malloc(sizeof(t_conf));
	g_conf->errcode = 0;
	g_conf->is_save = 0;
	g_conf->height = 100;
	g_conf->width = 100;
	g_conf->cameras = ft_glist_init();
	g_conf->objs = ft_glist_init();
	g_conf->ambient_light = ambiant_light_new(.2, 0xFF, 0xFF, 0xFF);
	g_conf->al_calculated = color_multi(g_conf->ambient_light.color,
		powf(g_conf->ambient_light.intensity, 2));
	g_conf->lights = ft_glist_init();
	g_conf->is_ambient = 1;
	g_conf->is_render = 0;
	g_conf->res_parsed = 0;
	g_conf->am_parsed = 0;
}
