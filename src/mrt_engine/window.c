/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:41:18 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 12:24:50 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

/*
** Window and image loader
*/

void	mrt_update_window(void)
{
	mlx_clear_window(g_conf->mlx.ptr, g_conf->mlx.win);
	mlx_put_image_to_window(g_conf->mlx.ptr, g_conf->mlx.win,
		g_conf->mlx.img.ptr, 0, 0);
}

void	mrt_img_init(void)
{
	g_conf->mlx.ptr = mlx_init();
	g_conf->mlx.img.ptr = mlx_new_image(g_conf->mlx.ptr,
	g_conf->width, g_conf->height);
	g_conf->mlx.img.addr = mlx_get_data_addr(g_conf->mlx.img.ptr,
		&g_conf->mlx.img.bpp, &g_conf->mlx.img.line_height,
		&g_conf->mlx.img.endian);
}

void	mrt_window_loop(void)
{
	mrt_img_init();
	g_conf->current_camera = g_conf->cameras;
	g_conf->mlx.win = mlx_new_window(g_conf->mlx.ptr,
		g_conf->width, g_conf->height, WINDOW_TITLE);
	camera_calc(mrt_current_camera());
	mrt_render();
	mrt_hooks();
	mlx_loop(g_conf->mlx.ptr);
}
