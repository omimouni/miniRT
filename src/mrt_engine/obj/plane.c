/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:33:06 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 16:29:09 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_object	*plane_new(t_point3 cords, t_vector3 normal, t_color color)
{
	t_plane		*tmp;
	t_object	*obj;

	tmp = malloc(sizeof(t_plane));
	tmp->cords = cords;
	tmp->normal = normal;
	obj = malloc(sizeof(t_object));
	obj->color = color;
	obj->object = tmp;
	obj->type = MRT_TYPE_PLANE;
	return (obj);
}

double		mrt_intersect_plane(t_mrt_ray *ray, t_object *obj)
{
	double	k1;
	double	k2;
	t_plane	*p;

	p = (t_plane *)obj->object;
	k1 = vec3_dot(vec3_sub(ray->origin, p->cords), p->normal);
	k2 = vec3_dot(ray->direction, p->normal);
	if (!k2)
		return (INFINITY);
	return (-k1 / k2);
}