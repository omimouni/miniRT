/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/31 17:51:13 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

static int	mrt_intersect_sphere(t_mrt_ray *ray, t_sphere *s, t_color color)
{
	double	k1;
	double	k2;
	double	k3;
	double	t1;
	double	t2;
	double	d;
	t_vector3	sub;

	k1 = vec3_dot(ray->direction, ray->direction);
	k2 = 2 * vec3_dot(vec3_sub(ray->origin, s->center), ray->direction);
	k3 = vec3_dot(vec3_sub(ray->origin, s->center),
		vec3_sub(ray->origin, s->center)) - s->diameter * s->diameter;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
		return 0x00000000;
	t1 = (-k2 + sqrt(d)) / (2 * k1);
	t2 = (-k2 - sqrt(d)) / (2 * k1);
	return 0xFFFFFFFF;
}

void		mrt_raytrace(t_mrt_ray	*ray, int *color)
{
	t_generic_list	*current;

	*color = 0x00000000;
	current = g_conf->objs;
	while (current != NULL)
	{
		if (((t_object *)current->obj)->type == MRT_TYPE_SPHERE)
		{
			*color = mrt_intersect_sphere(ray, ((t_object *)current->obj)->object, 
			((t_object *)current->obj)->color);
		}
		current = current->next;
	}
}
