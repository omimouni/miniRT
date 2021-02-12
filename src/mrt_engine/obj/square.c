/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:36:53 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/12 09:39:11 by omimouni         ###   ########.fr       */
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
