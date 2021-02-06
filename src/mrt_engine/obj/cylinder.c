/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:53:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 13:33:19 by omimouni         ###   ########.fr       */
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
	cy->dir = dir;
	cy->height = d[0];
	cy->diameter = d[1];
	obj->type = MRT_TYPE_CYLINDER;
	obj->color = cy->color;
	obj->object = cy;
	return (obj);
}

double	mrt_cylinder_intersect(t_mrt_ray *ray, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	det;
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
	else
		return (1);
}

t_vector3	mrt_cylinder_normal(t_pixel	*p)
{
	t_vector3	normal;
	t_cylinder	*cy;
	double		m;

	cy = (t_cylinder *)p->obj->object;
	m = vec3_dot(p->ray->direction, vec3_mult(p->t, cy->dir)) + 
		vec3_dot(vec3_sub(p->ray->origin, cy->cap), cy->dir);

	normal = vec3_sub(p->hitpoint, vec3_sub(cy->cap, vec3_mult(m, cy->dir)));
	return (normal);
}