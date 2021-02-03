/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:38:33 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/03 14:50:48 by omimouni         ###   ########.fr       */
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
	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win, 40, 40, 0xFFFFFFFF, "Test");
	printf("\n📷 Switch camera \n");
	if (g_conf->current_camera->next != NULL)
		g_conf->current_camera = g_conf->current_camera->next;
	else
		g_conf->current_camera = g_conf->cameras;
	camera_calc(mrt_current_camera());
	mrt_render();
	mrt_update_window();
}

static void		mrt_move_cam(int x, int y, int z)
{
	t_camera	*camera;

	printf("\n Moving camera by (%d, %d, %d) \n", x, y, z);
	camera = g_conf->cameras->obj;
	camera->origin.x += x;
	camera->origin.y += y;
	camera->origin.z += z;
	camera_calc(mrt_current_camera());
	mrt_render();
	mrt_update_window();
}

int				mrt_key_handler(int keycode)
{
	printf("%d \n", keycode);
	if (keycode == MRT_KEY_NUM5)
		mrt_next_cam();
	if (keycode == MRT_KEY_NUM4)
		mrt_move_cam(-1, 0, 0);
	if (keycode == MRT_KEY_NUM6)
		mrt_move_cam(1, 0, 0);
	if (keycode == MRT_KEY_NUM2)
		mrt_move_cam(0, -1, 0);
	if (keycode == MRT_KEY_NUM8)
		mrt_move_cam(0, 1, 0);
	if (keycode == MRT_KEY_ARROW_UP)
		mrt_move_cam(0, 0, -1);
	if (keycode == MRT_KEY_ARROW_DOWN)
		mrt_move_cam(0, 0, 1);
	if (keycode == MRT_KEY_ESC)
		mrt_quit();
	return (0);
}
