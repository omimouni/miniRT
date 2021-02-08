/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:41:18 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 23:27:15 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;
t_mlx_img	f;
int		g_img_height;
int		g_img_width;


void	mrt_update_window(void)
{
	mlx_clear_window(g_conf->mlx.ptr, g_conf->mlx.win);
	mlx_put_image_to_window(g_conf->mlx.ptr, g_conf->mlx.win,
		g_conf->mlx.img.ptr, 0, 0);
}

void	mrt_mlx_init(void)
{
	int		v;
	int		vv;

	g_conf->mlx.ptr = mlx_init();
	f.ptr = mlx_xpm_file_to_image(g_conf->mlx.ptr, "./textures/earth_01.xpm", &g_img_width, &g_img_height);
	f.addr = mlx_get_data_addr(f.ptr, &f.bpp, &f.line_height, &f.endian);

	g_conf->mlx.img.ptr = mlx_new_image(g_conf->mlx.ptr,
	g_conf->width, g_conf->height);
	g_conf->mlx.img.addr = mlx_get_data_addr(g_conf->mlx.img.ptr,
		&g_conf->mlx.img.bpp, &g_conf->mlx.img.line_height,
		&g_conf->mlx.img.endian);
}

void	mrt_window_loop(void)
{
	mrt_mlx_init();
	g_conf->current_camera = g_conf->cameras;
	g_conf->mlx.win = mlx_new_window(g_conf->mlx.ptr,
		g_conf->width, g_conf->height, WINDOW_TITLE);
	camera_calc(mrt_current_camera());
	mrt_render();
	mlx_key_hook(g_conf->mlx.win, mrt_key_handler, NULL);
	mlx_loop(g_conf->mlx.ptr);
}
