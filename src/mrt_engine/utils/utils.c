/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:54:56 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/29 23:17:59 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf *g_conf;

void	mrt_put_pixel(size_t x, size_t y, int color)
{
	char		*dst;
	t_mlx_img	*img;

	img = &g_conf->mlx.img;
	dst = img->addr + (y * img->line_height + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

t_mrt_ray	*mrt_ray_init(t_point3 orig, t_vector3 dir)
{
	t_mrt_ray	*ray;

	ray->origin = orig;
	ray->direction = dir;
	return (ray);
}

void	mrt_ray_free(t_mrt_ray *ray)
{
	free(ray);
}