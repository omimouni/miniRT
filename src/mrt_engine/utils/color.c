/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:18:05 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 09:18:30 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color			color_from_rgb(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color			color_from_hex(int hex)
{
	t_color	tmp;

	tmp.r = ((hex >> 16) & 0xFF);
	tmp.g = ((hex >> 8) & 0xFF);
	tmp.b = ((hex) & 0xFF);
	return (tmp);
}

int				hex_from_color(t_color color)
{
	return (color.r * 65536 + color.g * 256 + color.b);
}
