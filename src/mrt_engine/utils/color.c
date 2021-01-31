/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:18:05 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/31 11:49:18 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	color_rgba(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

t_color	color_new(int hex)
{
	t_color color;
	
	color.alpha = (hex & (0xFF << 24));
	color.r = (hex & (0xFF << 16));
	color.g = (hex & (0xFF << 8));
	color.b = (hex & 0xFF);
	return (color);
}

int	color_rgba_struct(t_color color)
{
	return (color.alpha << 24 | color.r << 16 | color.g << 8 | color.b);
}