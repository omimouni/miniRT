/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:15:40 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/07 18:38:29 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		mrt_cylinder_equation(t_cylinder *cy, t_mrt_ray *ray,
				double *t1, double *t2)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = vec3_dot(ray->direction, ray->direction) 
		- powf(vec3_dot(ray->direction, cy->dir), 2);
	b = 2 * (vec3_dot(ray->direction, vec3_sub(ray->origin, cy->cap)) 
		- vec3_dot(ray->direction, cy->dir) 
		* vec3_dot(vec3_sub(ray->origin, cy->cap), cy->dir));
	c = vec3_dot(vec3_sub(ray->origin, cy->cap),
		vec3_sub(ray->origin, cy->cap)) 
		- powf(vec3_dot(vec3_sub(ray->origin, cy->cap), cy->dir), 2) 
		- (cy->diameter / 2) * (cy->diameter / 2);
	det = b * b - 4 * a * c;
	if (det < 0)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
	}
	else
	{
		*t1 = (-b + sqrt(det)) / (2 * a);
		*t2 = (-b - sqrt(det)) / (2 * a);
	}
}

double			mrt_cylinder_calc_shape(t_cylinder *cy, t_mrt_ray *ray)
{
	double	t1;
	double	t2;

	mrt_cylinder_equation(cy, ray, &t1, &t2);
	return (t1 < t2 ? t1 : t2);
}