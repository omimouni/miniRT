/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:38:03 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/17 18:36:22 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

char	mrt_cylinder_check_cap(t_cylinder *cy, t_mrt_ray *ray, double t,
		char type)
{
	double	m;
	double	dist;

	m = vec3_dot(ray->direction, cy->dir) * t
		+ vec3_dot(vec3_sub(ray->origin, cy->cap), cy->dir);
	if (type == MRT_CYLINDER_CAP_TOP)
	{
		dist = vec3_length(vec3_sub(cy->cap, mrt_ray_point(t, ray)));
		if (dist < cy->diameter / 2 && m <= __FLT_EPSILON__)
			return (1);
	}
	else
	{
		dist = vec3_length(vec3_sub(vec3_add(cy->cap, vec3_mult(cy->height,
				cy->dir)), mrt_ray_point(t, ray)));
		// m = vec3_dot(ray->direction, cy->dir) * t +
		// 	vec3_dot(vec3_sub(ray->origin, vec3_add(cy->cap,
		// 	vec3_mult(cy->height, cy->dir))), cy->dir);
		// printf("%f \n", m);
		if (dist < cy->diameter / 2 && m >= cy->height)
			return (1);
	}
	return (0);
}

double	mrt_cylinder_calc_caps(t_cylinder *cy, t_mrt_ray *ray,
				char type)
{
	t_vector3	normal;
	double		a;
	double		b;

	normal = vec3_normalize(vec3_mult(type, cy->dir));
	if (type == MRT_CYLINDER_CAP_TOP)
	{
		a = vec3_dot(vec3_sub(ray->origin, cy->cap), normal);
		b = vec3_dot(ray->direction, normal);
	}
	else
	{
		a = vec3_dot(vec3_sub(ray->origin, vec3_add(cy->cap,
			vec3_mult(cy->height, cy->dir))), normal);
		b = vec3_dot(ray->direction, normal);
	}
	return (b != 0 ? (-a / b) : INFINITY);
}
