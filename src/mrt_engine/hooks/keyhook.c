/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:38:33 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 15:49:22 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

static void		mrt_quit(void)
{
	mlx_clear_window(g_conf->mlx.ptr, g_conf->mlx.win);
	mlx_destroy_image(g_conf->mlx.ptr, g_conf->mlx.img.ptr);
	mlx_destroy_window(g_conf->mlx.ptr, g_conf->mlx.win);
	printf("👋 Quitting !\n");
	exit(0);
}

static void		mrt_next_cam(void)
{
	printf("\n📷 Switch camera \n");
	if (g_conf->current_camera->next != NULL)
		g_conf->current_camera = g_conf->current_camera->next;
	else
		g_conf->current_camera = g_conf->cameras;
	camera_calc(mrt_current_camera());
	mrt_render();
}

static void		mrt_light_switch(void)
{
	if (g_conf->is_ambient)
		g_conf->is_ambient = 0;
	else
		g_conf->is_ambient = 1;
	mrt_render();
}

int				mrt_key_handler(int keycode)
{
	// printf("%d \n", keycode);
	if (g_conf->is_bonus)
		mrt_cam_event(keycode);
	(keycode == MRT_KEY_NUM5) ? mrt_next_cam() : NULL;
	(keycode == MRT_KEY_ESC) ? mrt_quit() : NULL;
	(keycode == MRT_KEY_NUM1) ? mrt_light_switch() : NULL;
	return (0);
}
