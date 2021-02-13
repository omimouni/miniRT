/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:57:08 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/13 15:16:44 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Möller–Trumbore Intesection algorithm
** v[5] = {point_a, point_b, point_c}
** e[2] = {edge_ab, edge_ac}
*/


double			mrt_triangle_intersection(t_mrt_ray *ray, t_object *obj)
{
	t_point3	v0;
	t_point3	v1;
	t_point3	v2;
	t_triangle	*tr;
	t_vector3	edge1;
	t_vector3	edge2;
	t_vector3	h;
	t_vector3	s;
	t_vector3	q;
	double		a, f, u, v, t;

	
	tr = (t_triangle *)obj->object;
	v0 = tr->point_a;
	v1 = tr->point_b;
	v2 = tr->point_c;
	edge1 = vec3_sub(v1, v0);
	edge2 = vec3_sub(v2, v0);
	
	h = vec3_cross(ray->direction, edge2);
	a = vec3_dot(edge1, h);
	if (a > -__FLT_EPSILON__ && a < __FLT_EPSILON__)
		return (INFINITY);
	f = 1 / a;
	s = vec3_sub(ray->origin, v0);
	u = f * vec3_dot(s, h);
	if (u < 0 || u > 1)
		return (INFINITY);
	
	q = vec3_cross(s, edge1);
	v = f * vec3_dot(ray->direction, q);
	if (v < 0 || u + v > 1)
		return (INFINITY);
	t = f * vec3_dot(edge2, q);
	if (t > __FLT_EPSILON__)
		return (t);
	else
		return (INFINITY);
}
