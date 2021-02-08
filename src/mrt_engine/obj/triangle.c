/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:24:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 09:16:12 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*triangle_new(t_point3 pa, t_point3 pb, t_point3 pc, t_color color)
{
	t_object	*obj;
	t_triangle	*tr;

	obj = malloc(sizeof(t_object));
	tr = malloc(sizeof(t_triangle));
	tr->point_a = pa;
	tr->point_b = pb; 
	tr->point_c = pc;
	tr->color = color;
	obj->type = MRT_TYPE_TRIANGLE;
	obj->color = color;
	obj->object = tr;
	return (obj);
}

double		triangle_intersection(t_mrt_ray *ray, t_object *obj)
{
}
