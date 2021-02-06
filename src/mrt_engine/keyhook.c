/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:38:33 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 20:13:01 by omimouni         ###   ########.fr       */
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
	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win, 40, 40, 0xFFFFFFFF, "Rendering ...");
	printf("\n📷 Switch camera \n");
	if (g_conf->current_camera->next != NULL)
		g_conf->current_camera = g_conf->current_camera->next;
	else
		g_conf->current_camera = g_conf->cameras;
	camera_calc(mrt_current_camera());
	mrt_render();
	mrt_update_window();
}

static void		mrt_move_cam_x(int x)
{
	t_camera	*camera;

	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win, 40, 40, 0xFFFFFFFF, "Rendering ...");
	printf("\n Moving camera by X= %d \n", x);
	camera = mrt_current_camera();
	camera->origin = vec3_add(camera->origin, vec3_mult(x, camera->right));
	camera_calc(camera);
	mrt_render();
	mrt_update_window();
}

static void		mrt_move_cam_y(int y)
{
	t_camera	*camera;

	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win, 40, 40, 0xFFFFFFFF, "Rendering ...");
	printf("\n Moving camera by Y= %d \n", y);
	camera = mrt_current_camera();
	camera->origin = vec3_add(camera->origin, vec3_mult(y, camera->up));
	camera_calc(camera);
	mrt_render();
	mrt_update_window();
}


static void		mrt_move_cam_z(int z)
{
	t_camera	*camera;

	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win, 40, 40, 0xFFFFFFFF, "Rendering ...");
	printf("\n Moving camera by Z= %d \n", z);
	camera = mrt_current_camera();
	camera->origin = vec3_add(camera->origin, vec3_mult(z, camera->normal));
	camera_calc(camera);
	mrt_render();
	mrt_update_window();
}

static void		mrt_rotate_cam_x(double x)
{
	t_camera	*camera;
	t_vector3	dir;

	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win, 40, 40, 0xFFFFFFFF, "Rendering ...");
	camera = mrt_current_camera();
	dir = vec3_add(camera->normal, vec3_mult(x, camera->right));
	dir = vec3_normalize(dir);
	camera->target = dir;
	camera_calc(camera);
	mrt_render();
	mrt_update_window();
}


static void		mrt_rotate_cam_y(double y)
{
	t_camera	*camera;
	t_vector3	dir;

	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win, 40, 40, 0xFFFFFFFF, "Rendering ...");
	camera = mrt_current_camera();
	dir = vec3_add(camera->normal, vec3_mult(y, camera->up));
	dir = vec3_normalize(dir);
	camera->target = dir;
	camera_calc(camera);
	mrt_render();
	mrt_update_window();
}

int				mrt_key_handler(int keycode)
{
	printf("%d \n", keycode);
	if (keycode == MRT_KEY_NUM5)
		mrt_next_cam();
	if (keycode == MRT_KEY_NUM4)
		mrt_move_cam_x(-1);
	if (keycode == MRT_KEY_NUM6)
		mrt_move_cam_x(1);
	if (keycode == MRT_KEY_NUM2)
		mrt_move_cam_y(1);
	if (keycode == MRT_KEY_NUM8)
		mrt_move_cam_y(-1);
	if (keycode == MRT_KEY_NUM7)
		mrt_move_cam_z(-1);
	if (keycode == MRT_KEY_NUM9)
		mrt_move_cam_z(1);
	if (keycode == MRT_KEY_ARROW_UP)
		mrt_rotate_cam_y(-.2);
	if (keycode == MRT_KEY_ARROW_DOWN)
		mrt_rotate_cam_y(.2);
	if (keycode == MRT_KEY_ARROW_LEFT)
		mrt_rotate_cam_x(-.2);
	if (keycode == MRT_KEY_ARROW_RIGHT)
		mrt_rotate_cam_x(.2);
	if (keycode == MRT_KEY_ESC)
		mrt_quit();
	return (0);
}
