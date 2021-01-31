/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:54 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 00:12:40 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

void static mrt_quit()
{
	mlx_clear_window(g_conf->mlx.ptr, g_conf->mlx.win);
	mlx_destroy_image(g_conf->mlx.ptr, g_conf->mlx.img.ptr);
	mlx_destroy_window(g_conf->mlx.ptr, g_conf->mlx.win);
	printf("< 👋  Quitting ! > \n");
	exit(0);
}

void static	mrt_next_cam()
{
	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win,
	g_conf->width / 2 - 60, g_conf->height / 2, 0xFFFFFF, "Rendering new scene");
	sleep(3);
	printf("-> Selecting next camera\n");
	g_conf->current_camera = camera_new_(vec3_new(0, 0, 0), vec3_new(0, 0, -1), 80);
	mrt_render();
	mrt_update_window();
}

int	mrt_key_handler(int keycode)
{
	// printf("%d\n", keycode);
	if (keycode == MRT_KEY_NUM5)
		mrt_next_cam();
	if (keycode == MRT_KEY_ESC)
		mrt_quit();
	return (0);
}
