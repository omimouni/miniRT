/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:26:20 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/11 17:46:03 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*square_new(t_point3 p, t_vector3 n, double size, t_color color)
{
	t_object	*tmp;
	t_square	*sq;

	tmp = malloc(sizeof(t_object));
	sq = malloc(sizeof(t_square));
	sq->point = p;
	sq->normal = n;
	sq->color = color;
	sq->size = size;
	tmp->color = color;
	tmp->type = MRT_TYPE_SQUARE;
	tmp->object = sq;
	return (tmp);
}

double	