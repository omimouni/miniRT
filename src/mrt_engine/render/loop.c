/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:40:21 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 09:11:21 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

t_vector3		mrt_ray_calc_dir(size_t x, size_t y)
{
	t_vector3	tmp;
	t_vector3	u;
	t_vector3	r;

	r = vec3_mult(g_conf->current_camera->scene_w * camera_position_x(x),
		g_conf->current_camera->right);
	u = vec3_mult(g_conf->current_camera->scene_h * camera_position_y(y),
		g_conf->current_camera->up);
	tmp = vec3_add(g_conf->current_camera->normal, u);
	tmp = vec3_add(tmp, r);
	return (vec3_normalize(tmp));
}

void			mrt_render_loop(void)
{
	size_t		i;
	size_t		j;
	t_mrt_ray	*ray;
	int			color;

	i = 0;
	ray = mrt_ray_init(g_conf->current_camera->origin);
	while (i < g_conf->width)
	{
		j = 0;
		while (j < g_conf->height)
		{
			mrt_ray_update_dir(&ray, mrt_ray_calc_dir(i, j));
			mrt_raytrace(ray, &color);
			if (g_conf->is_save)
				// @todo: add bmp renderer
				continue;
			else
				mrt_put_pixel(i, j, color);
			j++;
		}
		i++;
	}
}
