/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:57:08 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/17 17:35:21 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Möller–Trumbore Intesection algorithm
** v[5] = {point_a, point_b, point_c}
** e[2] = {edge_ab, edge_ac}
*/

static void		mrt_triangle_vex(t_triangle *tr, t_vector3 *vex)
{
	vex[0] = tr->point_a;
	vex[1] = tr->point_b;
	vex[2] = tr->point_c;
	vex[3] = vec3_sub(vex[1], vex[0]);
	vex[4] = vec3_sub(vex[2], vex[0]);
}

double			mrt_triangle_intersection(t_mrt_ray *ray, t_object *obj)
{
	t_vector3	vex[8];
	double		d[5];

	mrt_triangle_vex(obj->object, vex);
	vex[5] = vec3_cross(ray->direction, vex[4]);
	d[0] = vec3_dot(vex[3], vex[5]);
	if (d[0] > -__FLT_EPSILON__ && d[0] < __FLT_EPSILON__)
		return (INFINITY);
	d[1] = 1 / d[0];
	vex[6] = vec3_sub(ray->origin, vex[0]);
	d[2] = d[1] * vec3_dot(vex[6], vex[5]);
	if (d[2] < 0 || d[2] > 1)
		return (INFINITY);
	vex[7] = vec3_cross(vex[6], vex[3]);
	d[3] = d[1] * vec3_dot(ray->direction, vex[7]);
	if (d[3] < 0 || d[2] + d[3] > 1)
		return (INFINITY);
	d[4] = d[1] * vec3_dot(vex[4], vex[7]);
	if (d[4] > 0)
		return (d[4] - __FLT_EPSILON__);
	else
		return (INFINITY);
}
