/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:19:19 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 09:19:46 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_rotate_cam_x(double x)
{
	t_camera	*camera;
	t_vector3	dir;

	camera = mrt_current_camera();
	dir = vec3_add(camera->normal, vec3_mult(x, camera->right));
	dir = vec3_normalize(dir);
	camera->target = dir;
	camera_calc(camera);
	mrt_render();
	mrt_update_window();
}

void	mrt_rotate_cam_y(double y)
{
	t_camera	*camera;
	t_vector3	dir;

	camera = mrt_current_camera();
	dir = vec3_add(camera->normal, vec3_mult(y, camera->up));
	dir = vec3_normalize(dir);
	camera->target = dir;
	camera_calc(camera);
	mrt_render();
	mrt_update_window();
}