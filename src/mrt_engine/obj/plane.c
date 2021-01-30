/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:33:06 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/30 10:03:23 by omimouni         ###   ########.fr       */
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
	tmp->color = color;
	return (object_new(MRT_TYPE_PLANE, (void *)tmp));
}
