/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:53:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 11:04:46 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define MRT_NORMAL_CAP_TOP 1
#define MRT_NORMAL_CAP_END 2
#define MRT_NORMAL_CYLINDER 3

extern	t_conf	*g_conf;

t_object	*cylinder_new(t_point3 cap, t_vector3 dir, t_color color,
	double d[])
{
	t_object	*obj;
	t_cylinder	*cy;

	obj = malloc(sizeof(t_object));
	cy = malloc(sizeof(t_cylinder));
	cy->cap = cap;
	cy->dir = vec3_normalize(dir);
	cy->height = d[0];
	cy->diameter = d[1];
	obj->type = MRT_TYPE_CYLINDER;
	obj->color = color;
	obj->object = cy;
	return (obj);
}

double		mrt_cylinder_intersect(t_mrt_ray *ray, t_object *obj)
{
	double		tcylinder;
	double		tcy_cap_top;
	double		tcy_cap_end;
	t_cylinder	*cy;

	cy = (t_cylinder *)obj->object;
	tcylinder = mrt_cylinder_calc_shape(cy, ray);
	if (mrt_cylinder_check(cy, ray, tcylinder))
		return (tcylinder);
	if (g_conf->is_bonus)
	{
		tcy_cap_top = mrt_cylinder_calc_caps(cy, ray, MRT_CYLINDER_CAP_TOP);
		tcy_cap_end = mrt_cylinder_calc_caps(cy, ray, MRT_CYLINDER_CAP_END);
		if (mrt_cylinder_check_cap(cy, ray, tcy_cap_top, MRT_CYLINDER_CAP_TOP))
			return (tcy_cap_top);
		if (mrt_cylinder_check_cap(cy, ray, tcy_cap_end, MRT_CYLINDER_CAP_END))
			return (tcy_cap_end);
	}
	return (INFINITY);
}

double		mrt_cylinder_cast_shadow(t_pixel *p, t_object *obj, t_light *light)
{
	t_mrt_ray	*ray;
	double		t;

	ray = mrt_ray_init(p->hitpoint);
	ray->direction = light->dir;
	if (obj == p->obj)
		return (light->angle);
	t = mrt_cylinder_intersect(ray, obj);
	if (t < INFINITY && (t < light->distance && t > 0))
		return (0);
	return (light->angle);
}
