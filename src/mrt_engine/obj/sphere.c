/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:23:10 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/31 11:52:56 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_object	*sphere_new(t_point3 center, double diameter, t_color color)
{
	t_sphere	*tmp;
	t_object	*obj;

	tmp = malloc(sizeof(t_sphere));
	tmp->center = center;
	tmp->diameter = diameter;
	obj = malloc(sizeof(t_object));
	obj->type = MRT_TYPE_SPHERE;
	obj->object = (void *)tmp;
	obj->color = color;
	return (obj);
}