/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:34:16 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/17 16:42:36 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/*
** vex[6] = {u, v, a, b, c, d}
*/

static void		mrt_square_vex(t_square *sq, t_vector3 *vex)
{
	vex[0] = vec3_cross(sq->normal, vec3_new(0, 1, 1));
	vex[0] = vec3_normalize(vex[0]);
	vex[1] = vec3_cross(vex[0], sq->normal);
	vex[1] = vec3_normalize(vex[1]);

	vex[2] = vec3_add(vec3_add(vec3_mult(sq->size / 2, vex[1]), sq->point),
		vec3_mult(sq->size / 2, vex[0]));
	vex[3] = vec3_add(vex[2], vec3_mult(-sq->size, vex[1]));
	vex[4] = vec3_add(vex[3], vec3_mult(-sq->size, vex[0]));
	vex[5] = vec3_add(vex[4], vec3_mult(sq->size, vex[1]));
}

static double	mrt_square_t(double t, t_object *obj)
{
	free(obj->object);
	free(obj);
	return (t);
}

double			mrt_square_intersection(t_mrt_ray *ray, t_object *obj)
{
	t_vector3	vex[6];
	double		t;
	t_object	*tr;
	t_square	*sq;

	sq = (t_square *)obj->object;
	// Get square vertices
	mrt_square_vex(sq, vex);
	tr = triangle_new(vex[2], vex[3], vex[4], sq->color);
	t = mrt_triangle_intersection(ray, tr);
	if (t < INFINITY)
		return (mrt_square_t(t, tr));
	((t_triangle *)tr->object)->point_a = vex[4];
	((t_triangle *)tr->object)->point_b = vex[5];
	((t_triangle *)tr->object)->point_c = vex[2];
	t = mrt_triangle_intersection(ray, tr);
	if (t < INFINITY)
		return (mrt_square_t(t, tr));
	return (mrt_square_t(INFINITY, tr));
}
