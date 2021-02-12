/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:17:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/12 17:01:47 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_move_cam_x(int x)
{
	t_camera	*camera;

	printf("\n Moving camera by X= %d \n", x);
	camera = mrt_current_camera();
	camera->origin = vec3_add(camera->origin, vec3_mult(x, camera->right));
	camera_calc(camera);
	mrt_render();
}

void	mrt_move_cam_y(int y)
{
	t_camera	*camera;

	printf("\n Moving camera by Y= %d \n", y);
	camera = mrt_current_camera();
	camera->origin = vec3_add(camera->origin, vec3_mult(y, camera->up));
	camera_calc(camera);
	mrt_render();
}

void	mrt_move_cam_z(int z)
{
	t_camera	*camera;

	printf("\n Moving camera by Z= %d \n", z);
	camera = mrt_current_camera();
	camera->origin = vec3_add(camera->origin, vec3_mult(z, camera->normal));
	camera_calc(camera);
	mrt_render();
}

void	mrt_cam_event(int keycode)
{
	(keycode == MRT_KEY_NUM2) ? mrt_move_cam_y(1) : NULL;
	(keycode == MRT_KEY_NUM8) ? mrt_move_cam_y(-1) : NULL;
	(keycode == MRT_KEY_NUM4) ? mrt_move_cam_x(-1) : NULL;
	(keycode == MRT_KEY_NUM6) ? mrt_move_cam_x(1) : NULL;
	(keycode == MRT_KEY_NUM7) ? mrt_move_cam_z(-1) : NULL;
	(keycode == MRT_KEY_NUM9) ? mrt_move_cam_z(1) : NULL;
	(keycode == MRT_KEY_NUM9) ? mrt_move_cam_z(1) : NULL;
	(keycode == MRT_KEY_ARROW_UP) ? mrt_rotate_cam_y(-.2) : NULL;
	(keycode == MRT_KEY_ARROW_DOWN) ? mrt_rotate_cam_y(.2) : NULL;
	// (keycode == MRT_KEY_ARROW_LEFT) ? mrt_rotate_cam_x(-.2) : NULL;
	// (keycode == MRT_KEY_ARROW_RIGHT) ? mrt_rotate_cam_x(.2) : NULL;
}
