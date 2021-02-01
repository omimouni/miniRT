/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:18:05 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 18:27:12 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_color			color_from_rgb(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int				hex_from_color(t_color color)
{
	return (color.r * 65536 + color.g * 256 + color.b);
}

t_amblight		ambiant_light_new(double i, int r, int g, int b)
{
	t_amblight al;

	al.color = color_from_rgb(r, g, b);
	al.intensity = i;
	return (al);
}

t_color			color_add(t_color a, t_color b)
{
	t_color	c;

	c.r = ft_clamp_int(a.r + b.r, 0, 255);
	c.g = ft_clamp_int(a.g + b.g, 0, 255);
	c.b = ft_clamp_int(a.b + b.b, 0, 255);
	return (c);
}

t_color			color_multi(t_color a, double con)
{
	t_color	c;

	c.r = ft_clamp_int(a.r * con, 0, 255);
	c.g = ft_clamp_int(a.g * con, 0, 255);
	c.b = ft_clamp_int(a.b * con, 0, 255);
	return (c);
}
