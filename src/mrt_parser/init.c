/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:55:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/31 18:35:48 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;


// @todo: test scene
void static testScene()
{
	g_conf->current_camera = camera_new_(vec3_new(0, 0, 0), vec3_new(0, 0, -1), 90);
	g_conf->objs = ft_glist_add(g_conf->objs, 
		sphere_new(vec3_new(10, 0, -70), 1, color_new(0xFFFF00))
	);
	g_conf->objs = ft_glist_add(g_conf->objs, 
		sphere_new(vec3_new(1, -2, -20), 1, color_new(0xFFFF00FF))
	);
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
	testScene();
}
