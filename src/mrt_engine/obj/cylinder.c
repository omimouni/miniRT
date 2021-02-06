/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:53:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 16:55:53 by omimouni         ###   ########.fr       */
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

double	mrt_cylinder_intersect(t_mrt_ray *ray, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	det;
	double	t1;
	double	t2;
	double	m;
	t_vector3	x;
	t_cylinder	*cy;

	cy = (t_cylinder *)obj->object;
	x = vec3_sub(ray->origin, cy->cap);

	a = vec3_dot(ray->direction, ray->direction)
		- powf(vec3_dot(ray->direction, cy->dir), 2);
	b = 2 * (vec3_dot(ray->direction, x) - vec3_dot(ray->direction, cy->dir)
		* vec3_dot(x, cy->dir));
	c = vec3_dot(x, x) - powf(vec3_dot(x, cy->dir), 2) 
		- cy->diameter * cy->diameter;
	det = b * b - 4 * a * c;
	if (det < 0)
		return (INFINITY);
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	m = 0;
	if (t1 < t2)
	{
		m = vec3_dot(ray->direction, cy->dir) * t1 + 
		vec3_dot(vec3_sub(ray->origin, cy->cap), cy->dir);
		if (m > cy->height || m < 0)
			return (INFINITY);
		return mrt_cylinder_cap(m, t1, ray, cy);
	}
	else
	{
		m = vec3_dot(ray->direction, cy->dir) * t2 + 
		vec3_dot(vec3_sub(ray->origin, cy->cap), cy->dir);
		if (m >= cy->height || m < 0)
			return (INFINITY);
		return mrt_cylinder_cap(m, t2, ray, cy);
	}
}

t_vector3	mrt_cylinder_normal(t_pixel	*p)
{
	t_vector3	normal;
	t_cylinder	*cy;
	double		m;

	cy = (t_cylinder *)p->obj->object;
	m = vec3_dot(p->ray->direction, cy->dir) * p->t + 
		vec3_dot(vec3_sub(p->ray->origin, cy->cap), cy->dir);
	p->c_m = m;
	normal = vec3_sub(p->hitpoint, vec3_sub(cy->cap, vec3_mult(-m, cy->dir)));
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
		return (.05);
	return (light->angle);
}