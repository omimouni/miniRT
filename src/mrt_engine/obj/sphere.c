/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:23:10 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/04 01:30:29 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_object	*sphere_new(t_point3 center, double diameter, t_color color)
{
	t_sphere	*tmp;
	t_object	*obj;

	tmp = malloc(sizeof(t_sphere));
	tmp->center = center;
	tmp->diameter = diameter;
	obj = malloc(sizeof(t_object));
	obj->type = MRT_TYPE_SPHERE;
	obj->object = (void *)tmp;
	obj->color = color;
	return (obj);
}

double		mrt_intersect_sphere_equation(t_mrt_ray *ray, t_sphere *s,
	double *t1, double *t2)
{
	double		k1;
	double		k2;
	double		k3;
	double		det;

	k1 = vec3_dot(ray->direction, ray->direction);
	k2 = 2 * vec3_dot(vec3_sub(ray->origin, s->center), ray->direction);
	k3 = vec3_dot(vec3_sub(ray->origin, s->center),
		vec3_sub(ray->origin, s->center)) - s->diameter * s->diameter;
	det = k2 * k2 - 4 * k1 * k3;
	if (det < 0)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
	}
	else
	{
		*t1 = (-k2 + sqrt(det)) / (2 * k1);
		*t2 = (-k2 - sqrt(det)) / (2 * k1);
	}
	return (det);
}

double		mrt_intersect_sphere(t_mrt_ray *ray, t_object *obj)
{
	double		t1;
	double		t2;

	if (mrt_intersect_sphere_equation(ray, obj->object, &t1, &t2) < 0)
		return (INFINITY);
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

double		mrt_sphere_cast_shadow(t_pixel *p, t_object *obj, t_light *light)
{
	t_mrt_ray	*ray;
	double		t;

	ray = mrt_ray_init(p->hitpoint);
	ray->direction = light->dir;
	if (obj == p->obj)
		return (light->angle);
	t = mrt_intersect_sphere(ray, obj);
	if (t < INFINITY && (t < light->distance && t > 0))
		return (.05);
	return (light->angle);
}
