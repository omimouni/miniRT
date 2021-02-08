/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:24:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 12:06:06 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*triangle_new(t_point3 pa, t_point3 pb, t_point3 pc,
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

double		mrt_triangle_intersection(t_mrt_ray *ray, t_object *obj)
{
	t_point3	vertex;
	t_triangle	*tr;
	t_vector3	v1;
	t_vector3	v2;
	t_vector3	vn;
	double		k1;
	double		k2;
	double		t;
	t_point3	c;

	tr = (t_triangle *)obj->object;
	// Calc vectors
	v1 = vec3_sub(tr->point_b, tr->point_a);
	v2 = vec3_sub(tr->point_c, tr->point_a);
	vn = vec3_normalize(vec3_cross(v1, v2));
	// Calc plane
	k1 = vec3_dot(vec3_sub(ray->origin, tr->point_a), vn);
	k2 = vec3_dot(ray->direction, vn);
	t = k2 == 0 ? INFINITY : (-k1 / k2);

	return (t);
}
