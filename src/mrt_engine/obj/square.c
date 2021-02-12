/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:36:53 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/12 12:51:34 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*square_new(t_point3 p, t_vector3 n, double s, t_color c)
{
	t_object	*obj;
	t_square	*sq;

	obj = malloc(sizeof(t_object));
	sq = malloc(sizeof(t_square));
	sq->point = p;
	sq->normal = n;
	sq->size = s;
	sq->color = c;
	obj->color = c;
	obj->type = MRT_TYPE_SQUARE;
	obj->object = sq;
	return (obj);
}

double		mrt_square_intersection(t_mrt_ray *ray, t_object *obj)
{
	t_vector3	u;
	t_vector3	v;
	double		k1;
	double		k2;
	t_vector3	ux;
	t_vector3	vx;
	double		t;
	t_square	*sq;

	sq = (t_square *)obj->object;
	
	// Find a corner
	t_point3	pa;
	t_vector3	e1;
	t_vector3	e2;

	u = vec3_cross(sq->normal, mrt_current_camera()->normal);
	v = vec3_cross(u, sq->normal);
	ux = vec3_mult(3, u);
	vx = vec3_mult(3, v);
	pa = vec3_add(vec3_add(sq->point, ux), vx);
	e1 = vec3_add(pa, vec3_mult(-6, u));
	e2 = vec3_add(pa, vec3_mult(-6, v));

	// Calculate Plane intersection	
	k1 = vec3_dot(vec3_sub(ray->origin, sq->point), sq->normal);
	k2 = vec3_dot(ray->direction, sq->normal);
	if (!k2)
		return (INFINITY);
	t = -k1 / k2;

	// Limit square
	// k1 = 
	
	return (t);
}
