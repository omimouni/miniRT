/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:33:06 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/03 18:58:05 by omimouni         ###   ########.fr       */
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

double		mrt_plane_cast_shadow(t_pixel *p, t_object *obj, t_light *light)
{
	t_mrt_ray	*ray;
	double		t;
	t_vector3	tmp;

	ray = mrt_ray_init(p->hitpoint);
	tmp = light->dir;
	tmp.x += .000001;
	tmp.y += .000001;
	tmp.z += .000001;
	tmp = vec3_normalize(tmp);
	ray->direction = tmp;
	if (obj == p->obj)
		return (light->angle);
	t = mrt_intersect_plane(ray, obj);
	if (t < INFINITY && (t < light->distance && t > 0))
		return (0);
	return (light->angle);
}
