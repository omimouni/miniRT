/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:18:05 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 15:25:24 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	hex_from_rgba(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

t_color	color_from_rgba(int r, int g, int b, int a)
{
	int	color;

	color = hex_from_rgba(r, g, b, a);
	return (color_from_hex(color));
}

t_color	color_from_hex(int hex)
{
	t_color color;
	
	color.alpha = (hex & (0xFF << 24));
	color.r = (hex & (0xFF << 16));
	color.g = (hex & (0xFF << 8));
	color.b = (hex & 0xFF);
	return (color);
}

int	hex_from_color(t_color color)
{
	return (color.alpha << 24 | color.r << 16 | color.g << 8 | color.b);
}

t_amblight	ambiant_light_new(double i, int r, int g, int b)
{
	t_amblight al;

	al.color = color_from_rgba(r, g, b, 0xFF);
	al.intensity = i;
	return (al);
}