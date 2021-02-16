/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 07:59:15 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/16 18:14:03 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		mrt_cylinder_normal_calc(t_pixel *p, double *m, double *l,
				char type)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)p->obj->object;
	*l = vec3_length(vec3_sub(vec3_add(cy->cap,
			vec3_mult(cy->height, cy->dir)), mrt_ray_point(p->t, p->ray)));
	if (type == MRT_CYLINDER_CAP_TOP)
		*m = vec3_dot(p->ray->direction, cy->dir) * p->t +
			vec3_dot(vec3_sub(p->ray->origin, cy->cap), cy->dir);
	else
		*m = vec3_dot(p->ray->direction, cy->dir) * p->t +
			vec3_dot(vec3_sub(p->ray->origin, vec3_add(cy->cap,
			vec3_mult(cy->height, cy->dir))), cy->dir);
}

t_vector3		mrt_cylinder_normal(t_pixel *p)
{
	t_vector3	normal;
	double		m;
	double		l;
	t_cylinder	*cy;

	cy = (t_cylinder *)p->obj->object;
	mrt_cylinder_normal_calc(p, &m, &l, MRT_CYLINDER_CAP_TOP);
	p->is_cap = 1;
	if (m <= __FLT_EPSILON__)
		normal = vec3_mult(-1, cy->dir);
	else
	{
		p->is_cap = 0;
		normal = vec3_sub(p->hitpoint, vec3_sub(cy->cap,
					vec3_mult(-m, cy->dir)));
	}
	mrt_cylinder_normal_calc(p, &m, &l, MRT_CYLINDER_CAP_END);
	if (m <= __FLT_EPSILON__ && l <= cy->diameter / 2)
	{
		p->is_cap = 1;
		normal = vec3_mult(1, cy->dir);
	}
	return (normal);
}
