/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:15:12 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 09:13:13 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light			*light_new(t_point3 point, double brightness, t_color color)
{
	t_light	*l;

	l = malloc(sizeof(t_light));
	l->brightness = brightness;
	l->color = color;
	l->point = point;
	return (l);
}

t_amblight		ambiant_light_new(double i, int r, int g, int b)
{
	t_amblight al;

	al.color = color_from_rgb(r, g, b);
	al.intensity = i;
	return (al);
}
