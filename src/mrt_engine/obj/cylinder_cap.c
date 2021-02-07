/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:38:03 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/07 18:52:21 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

double	mrt_cylinder_render_caps(t_cylinder *cy, t_mrt_ray *ray,
		double p, char type)
{
	double	dist;

	if (type == MRT_CYLINDER_CAP_TOP)
		dist = vec3_length(vec3_sub(cy->cap, mrt_ray_point(p, ray)));
	else
		dist = vec3_length(vec3_sub(vec3_add(cy->cap, vec3_mult(cy->height, 
	cy->dir)), mrt_ray_point(p, ray)));

	printf("%f \n", dist);
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