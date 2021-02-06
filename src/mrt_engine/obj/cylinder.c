/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:13:29 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/05 22:24:52 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_object	*cylinder_new(t_point3	cap, t_vector3 dir, double dimension[],
			t_color color)
{
	t_object	*tmp;
	t_cylinder	*c;

	tmp = malloc(sizeof(t_object));
	tmp->type = MRT_TYPE_CYLINDER;
	tmp->color = color;
	c = malloc(sizeof(t_cylinder));
	c->cap = cap;
	c->dir = dir;
	c->height = dimension[0];
	c->diameter = dimension[1];
	tmp->object = c;
	return (tmp);
}

double	mrt_intersect_cylinder(t_mrt_ray *ray, t_object *obj)
{
	t_cylinder	*cy;
	double		a;
	double		b;
	double		c;
	double		det;

	cy = (t_cylinder *)obj->object;
	a = vec3_dot(ray->direction, ray->direction)
		- powf(vec3_dot(ray->direction, cy->dir), 2);
	b = vec3_dot(ray->direction, vec3_sub(mrt_current_camera()->origin,
		ray->origin)) - vec3_dot(ray->direction, cy->dir) *
		vec3_dot(vec3_sub(mrt_current_camera()->origin, ray->origin), cy->dir);
	b = b * 2;
	c = vec3_dot(vec3_sub(mrt_current_camera()->origin, ray->origin)
		, vec3_sub(mrt_current_camera()->origin, ray->origin)) -
		powf(vec3_dot(vec3_sub(mrt_current_camera()->origin, ray->origin),
		ray->direction), 2) - cy->diameter * cy->diameter;
	det = b * b - 4 * a * c;
	if (det <= 0)
		printf("%f \n", det);
	if (det >= 0)
		return (0);
	else
		return (INFINITY);
	// printf("%f %f %f \n", a, b, c);
}