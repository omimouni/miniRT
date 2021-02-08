/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:14:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 09:15:58 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mrt_ray			*mrt_ray_init(t_point3 orig)
{
	t_mrt_ray	*ray;

	ray = malloc(sizeof(t_mrt_ray));
	ray->origin = orig;
	ray->color = color_from_rgb(0, 0, 0);
	return (ray);
}

t_point3			mrt_ray_point(double t, t_mrt_ray *ray)
{
	t_point3	pt;

	pt = vec3_mult(t, ray->direction);
	pt = vec3_add(ray->origin, pt);
	return (pt);
}

static t_vector3	mrt_ray_calc_dir(size_t x, size_t y)
{
	t_vector3	tmp;
	t_vector3	u;
	t_vector3	r;

	r = vec3_mult(mrt_current_camera()->scene_w * camera_position_x(x),
		mrt_current_camera()->right);
	u = vec3_mult(mrt_current_camera()->scene_h * camera_position_y(y),
		mrt_current_camera()->up);
	tmp = vec3_add(mrt_current_camera()->normal, u);
	tmp = vec3_add(tmp, r);
	return (vec3_normalize(tmp));
}

void				mrt_ray_update(t_mrt_ray **ray, size_t px, size_t py)
{
	(*ray)->direction = mrt_ray_calc_dir(px, py);
	(*ray)->px = px;
	(*ray)->py = py;
}
