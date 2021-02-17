/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:36:53 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/17 16:34:30 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*square_new(t_point3 p, t_vector3 n, double s, t_color c)
{
	t_object	*obj;
	t_square	*sq;

	obj = malloc(sizeof(t_object));
	sq = malloc(sizeof(t_square));
	sq->point = p;
	sq->normal = n;
	sq->size = s;
	sq->color = c;
	obj->color = c;
	obj->type = MRT_TYPE_SQUARE;
	obj->object = sq;
	return (obj);
}

double	mrt_square_cast_shadow(t_pixel *p, t_object *obj, t_light *light)
{
	t_mrt_ray	*ray;
	double		t;

	ray = mrt_ray_init(p->hitpoint);
	ray->direction = light->dir;
	if (obj == p->obj)
	{
		free(ray);
		return (light->angle);
	}
	t = mrt_square_intersection(ray, obj);
	free(ray);
	if (t < INFINITY && (t < light->distance && t > 0))
	{
		p->is_shadow = 1;
		return (0);
	}
	return (light->angle);
}