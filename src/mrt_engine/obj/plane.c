/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:33:06 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/31 11:47:31 by omimouni         ###   ########.fr       */
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
	obj = malloc(sizeof(obj));
	obj->color = color;
	obj->object = tmp;
	obj->type = MRT_TYPE_PLANE;
	return (obj);
}
