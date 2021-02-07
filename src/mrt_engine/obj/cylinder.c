/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:53:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/07 18:53:12 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

double		mrt_cylinder_cap(double m, double t, t_mrt_ray *ray,
			t_cylinder *cy)
{
	t_vector3	a;

	if (m < 0)
		return (INFINITY);
	return (t);
}

/*
** Cylinder Intersection 
** 
*/

double	mrt_cylinder_intersect(t_mrt_ray *ray, t_object *obj)
{
	double		tcylinder;
	double		tcy_cap_top;
	double		tcy_cap_end;

	double	t3;
	double	k1;
	double	k2;
	double	m;
	t_vector3	x;
	t_cylinder	*cy;
	t_vector3	norm;

	cy = (t_cylinder *)obj->object;

	// Point of Intersection with Cylinder Shape
	tcylinder = mrt_cylinder_calc_shape((t_cylinder *)obj->object, ray);
	
	// // Calculate Caps ---
	// norm = vec3_normalize(vec3_mult(-1, cy->dir));
	// k1 = vec3_dot(vec3_sub(ray->origin, cy->cap), norm);
	// k2 = vec3_dot(ray->direction, norm);
	// if (!k2)
	// 	t3 = INFINITY;
	// else
	// 	t3 = (-k1 / k2);

	// Calculating Intersection with caps
	tcy_cap_top = mrt_cylinder_calc_caps(cy, ray, MRT_CYLINDER_CAP_TOP);
	// tcy_cap_end = mrt_cylinder_calc_caps(cy, ray, MRT_CYLINDER_CAP_END);

	// Calculate Caps ---
	double l = vec3_length(vec3_sub(cy->cap, mrt_ray_point(tcy_cap_top, ray)));
	m = vec3_dot(ray->direction, cy->dir) * tcy_cap_top + 
	vec3_dot(vec3_sub(ray->origin, cy->cap), cy->dir);

	// Limiting the cylinder 
	m = vec3_dot(ray->direction, cy->dir) * tcylinder + 
	vec3_dot(vec3_sub(ray->origin, cy->cap), cy->dir);
	if (m <= cy->height && m >= __FLT_EPSILON__)
		return (tcylinder);
	if (l < cy->diameter / 2 && m <= __FLT_EPSILON__)
	{
		return (tcy_cap_top);
	}
	return (INFINITY);
}

t_vector3	mrt_cylinder_normal(t_pixel	*p)
{
	t_vector3	normal;
	t_cylinder	*cy;
	double		m;


	cy = (t_cylinder *)p->obj->object;
	m = vec3_dot(p->ray->direction, cy->dir) * p->t + 
		vec3_dot(vec3_sub(p->ray->origin, cy->cap), cy->dir);
	if (m <= __FLT_EPSILON__)
	{
		p->light_cof = 10;
		normal = vec3_mult(-1, cy->dir);
	}
	else
	{
		p->c_m = m;
		normal = vec3_sub(p->hitpoint, vec3_sub(cy->cap, vec3_mult(-m, cy->dir)));
	}
	return (normal);
}

double	mrt_cylinder_cast_shadow(t_pixel *p, t_object *obj, t_light *light)
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