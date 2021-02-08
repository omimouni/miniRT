/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:51:29 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 16:51:41 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

	c.r = ft_clamp_int((a.r * con), 0, 255);
	c.g = ft_clamp_int((a.g * con), 0, 255);
	c.b = ft_clamp_int((a.b * con), 0, 255);
	return (c);
}
