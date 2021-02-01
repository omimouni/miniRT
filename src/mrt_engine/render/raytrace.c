/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 09:23:40 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

static double	mrt_intersect_sphere_equation(t_mrt_ray *ray, t_sphere *s,
	double *t1, double *t2)
{
	double		k1;
	double		k2;
	double		k3;
	double		det;

	k1 = vec3_dot(ray->direction, ray->direction);
	k2 = 2 * vec3_dot(vec3_sub(ray->origin, s->center), ray->direction);
	k3 = vec3_dot(vec3_sub(ray->origin, s->center),
		vec3_sub(ray->origin, s->center)) - s->diameter * s->diameter;
	det = k2 * k2 - 4 * k1 * k3;
	if (det < 0)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
	}
	else
	{
		*t1 = (-k2 + sqrt(det)) / (2 * k1);
		*t2 = (-k2 - sqrt(det)) / (2 * k1);
	}
	return (det);
}

static int		mrt_intersect_sphere(t_mrt_ray *ray, t_sphere *s, t_color color)
{
	double		t1;
	double		t2;
	double		d;

	if (mrt_intersect_sphere_equation(ray, s, &t1, &t2) < 0)
		return (-1);
	return (color_rgba_struct(color));
}

void			mrt_raytrace(t_mrt_ray *ray, int *color)
{
	t_generic_list	*current;
	t_object		*obj;
	int				c;

	*color = 0x00000000;
	current = g_conf->objs;
	while (current != NULL)
	{
		if (((t_object *)current->obj)->type == MRT_TYPE_SPHERE)
		{
			obj = (t_object *)current->obj;
			c = mrt_intersect_sphere(ray, obj->object, obj->color);
			if (c > 0)
				*color = color_rgba_struct(obj->color);
		}
		current = current->next;
	}
}
