/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:24:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/17 17:39:37 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object		*triangle_new(t_point3 pa, t_point3 pb, t_point3 pc,
			t_color color)
{
	t_object	*obj;
	t_triangle	*tr;

	obj = malloc(sizeof(t_object));
	tr = malloc(sizeof(t_triangle));
	tr->point_a = pa;
	tr->point_b = pb;
	tr->point_c = pc;
	tr->color = color;
	obj->type = MRT_TYPE_TRIANGLE;
	obj->color = color;
	obj->object = tr;
	return (obj);
}

t_vector3		mrt_triangle_normal(t_pixel *p)
{
	t_triangle	*tr;
	t_vector3	edge1;
	t_vector3	edge2;
	t_vector3	normal;

	tr = (t_triangle *)p->obj->object;
	edge1 = vec3_sub(tr->point_b, tr->point_a);
	edge2 = vec3_sub(tr->point_c, tr->point_a);
	normal = vec3_cross(edge1, edge2);
	return (normal);
}
double			mrt_triangle_cast_shadow(t_pixel *p, t_object *obj,
			t_light *light)
{
	double		t;
	t_mrt_ray	*ray;

	ray = mrt_ray_init(p->hitpoint);
	ray->direction = light->dir;
	if (obj == p->obj)
	{
		free(ray);
		return (light->angle);
	}
	t = mrt_triangle_intersection(ray, obj);
	free(ray);
	if (t < INFINITY && (t < light->distance && t > 0))
		return (0);
	return (light->angle);
}
