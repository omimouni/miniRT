/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:38:33 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 14:12:30 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
	mrt_update_window();
}

static void		mrt_move_cam(int x, int y)
{
	t_camera	*camera;

	printf("\n Moving camera by x=%d y=%d\n", x, y);
	camera = mrt_current_camera();
	camera->origin.x += x;
	camera->origin.y += y;
	camera_calc(mrt_current_camera());
	mrt_render();
	mrt_update_window();
}

int				mrt_key_handler(int keycode)
{
	// printf("%d \n", keycode);
	if (keycode == MRT_KEY_NUM5)
		mrt_next_cam();
	if (keycode == MRT_KEY_NUM4)
		mrt_move_cam(1, 0);
	if (keycode == MRT_KEY_NUM6)
		mrt_move_cam(-1, 0);
	if (keycode == MRT_KEY_NUM2)
		mrt_move_cam(0, 1);
	if (keycode == MRT_KEY_NUM8)
		mrt_move_cam(0, -1);
	if (keycode == MRT_KEY_ESC)
		mrt_quit();
	return (0);
}
