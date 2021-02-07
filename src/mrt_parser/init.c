/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:55:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/07 12:05:12 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

static void	obj_add(t_object *ob)
{
	g_conf->objs = ft_glist_add(g_conf->objs, ob);
}
// @todo: test scene
static void testScene()
{
	// Cameras ---
	g_conf->cameras = ft_glist_add(g_conf->cameras,
			camera_new_(vec3_new(0, 0, -5), vec3_new(0, 0, -1), 70));
	g_conf->cameras = ft_glist_add(g_conf->cameras,
			camera_new_(vec3_new(0, 0, -20), vec3_new(0, 0, 1), 70));
	// g_conf->cameras = ft_glist_add(g_conf->cameras,
	// 		camera_new_(vec3_new(0, 0, 0), vec3_new(0, 0, -1), 70));

	// Objs ------
	double d[] = {0, 0};
	obj_add(plane_new(vec3_new(0, -5, 0), vec3_new(0, 1, 0), color_from_rgb(255, 255, 255)));
	// obj_add(plane_new(vec3_new(0, 10, 0), vec3_new(0, -1, 0), color_from_rgb(255, 255, 255)));

	d[0] = 20;
	d[1] = .5;
	// obj_add(cylinder_new(vec3_new(-3, -10, -10), vec3_new(0, 1, 0), color_from_rgb(0, 255, 255), d));
	// obj_add(cylinder_new(vec3_new(3, -10, -10), vec3_new(0, 1, 0), color_from_rgb(0, 255, 255), d));
	// obj_add(cylinder_new(vec3_new(-3, -10, -20), vec3_new(0, 1, 0), color_from_rgb(0, 255, 255), d));
	// obj_add(cylinder_new(vec3_new(3, -10, -20), vec3_new(0, 1, 0), color_from_rgb(0, 255, 255), d));
	d[0] = 5;
	d[1] = .5;
	obj_add(cylinder_new(vec3_new(0, 0, -15), vec3_new(.5, 0, 1), color_from_rgb(241, 196, 15), d));
	// g_conf->objs = ft_glist_add(g_conf->objs, sphere_new(vec3_new(0, 0, -15), 2,
	// 	color_from_rgb(241, 196, 15)));
	// g_conf->objs = ft_glist_add(g_conf->objs, sphere_new(vec3_new(0, 0, -20), 5,
	// 	color_from_rgb(155, 89, 182)));

	
	// g_conf->objs = ft_glist_add(g_conf->objs, 
	// 	sphere_new(vec3_new(0, 0, -20), 2, color_from_rgb(192, 57, 43)));
	// g_conf->objs = ft_glist_add(g_conf->objs, 
	// 	sphere_new(vec3_new(1, 3, -7), 1.5, color_from_rgb(141, 85, 36)));
	// g_conf->objs = ft_glist_add(g_conf->objs, 
	// 	sphere_new(vec3_new(-2, 5, -7), 3, color_from_rgb(141, 0, 0)));
	// // g_conf->objs = ft_glist_add(g_conf->objs, 
	// // 	sphere_new(vec3_new(-1, 0, -4), 1.5, color_from_rgb(141, 85, 36)));
	// g_conf->objs = ft_glist_add(g_conf->objs, plane_new(vec3_new(0, -2, 0),
	// 	vec3_new(0, 1, 0), color_from_rgb(0xFF, 0xff, 0xFF)));

	// Lights ----
	g_conf->lights = ft_glist_add(g_conf->lights,
			light_new(vec3_new(2, 4, -5), .5, color_from_rgb(255, 255, 255)));
	// g_conf->lights = ft_glist_add(g_conf->lights,
	// 		light_new(vec3_new(4, 10, -6), .5, color_from_rgb(255, 0, 255)));

}

void	mrt_init(void)
{
	g_conf = (t_conf *)malloc(sizeof(t_conf));
	g_conf->errcode = 0;
	g_conf->is_save = 0;
	g_conf->is_bonus = 0;
	g_conf->height = 423; //423;
	g_conf->width = 752; //752;
	g_conf->cameras = ft_glist_init();
	g_conf->objs = ft_glist_init();
	g_conf->ambient_light = ambiant_light_new(.2, 0xFF, 0xFF, 0xFF);
	// g_conf->ambient_light = ambiant_light_new(0.09, 241, 196, 15);
	g_conf->al_calculated = color_multi(g_conf->ambient_light.color,
		powf(g_conf->ambient_light.intensity, 2));
	g_conf->lights = ft_glist_init();
	testScene();
}
