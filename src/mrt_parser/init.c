/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:55:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 13:32:58 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;


// @todo: test scene
static void testScene()
{
	g_conf->current_camera = camera_new_(vec3_new(0, 0, 1),
			vec3_new(0, 0, -1), 90);
	
	// g_conf->objs = ft_glist_add(g_conf->objs, 
	// 	sphere_new(vec3_new(1.5, 0, -10), 2, color_from_rgb(192, 57, 43)));
	g_conf->objs = ft_glist_add(g_conf->objs, 
		sphere_new(vec3_new(0, 0, -6), .5, color_from_rgb(41, 128, 185)));

	g_conf->lights = ft_glist_add(g_conf->lights,
			light_new(vec3_new(0, 0, 0), .5, color_from_rgb(255, 255, 255)));
}

void	mrt_init(void)
{
	g_conf = (t_conf *)malloc(sizeof(t_conf));
	g_conf->errcode = 0;
	g_conf->is_save = 0;
	g_conf->height = 423; //423;
	g_conf->width = 752; //752;
	g_conf->cameras = ft_glist_init();
	g_conf->objs = ft_glist_init();
	g_conf->ambient_light = ambiant_light_new(.09, 0xFF, 0xFF, 0xFF);
	// g_conf->ambient_light = ambiant_light_new(0.09, 241, 196, 15);
	g_conf->al_calculated = color_multi(g_conf->ambient_light.color,
		g_conf->ambient_light.intensity);
	g_conf->lights = ft_glist_init();
	testScene();
}
