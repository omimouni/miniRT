/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:40:21 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 09:54:43 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void				mrt_render_loop(size_t swidth, size_t width ,
	size_t sheight, size_t height)
{
	size_t		i;
	size_t		j;
	t_mrt_ray	*ray;

	width = ft_clamp_int(width, 0, g_conf->width);
	height = ft_clamp_int(width, 0, g_conf->height);
	i = swidth;
	ray = mrt_ray_init(mrt_current_camera()->origin);
	while (i < width)
	{
		j = sheight;
		while (j < height)
		{
			mrt_ray_update(&ray, i, j);
			// vec3_show(ray->direction);
			mrt_raytrace(ray);
			if (g_conf->is_save)
				continue;
			else
				mrt_put_pixel(i, j, ray->color);
			j++;
		}
		i++;
	}
	free(ray);
}
