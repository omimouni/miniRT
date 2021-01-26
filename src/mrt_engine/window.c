/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:41:18 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/26 11:42:37 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;


void	mrt_update_window()
{
	mlx_put_image_to_window(g_conf->mlx.ptr, g_conf->mlx.win,
		g_conf->mlx.img.ptr, 0, 0);
}

static void	mrt_mlx_init(void)
{
	g_conf->mlx.ptr = mlx_init();
	g_conf->mlx.img.ptr = mlx_new_image(g_conf->mlx.ptr,
		g_conf->width, g_conf->height);
	g_conf->mlx.img.addr = mlx_get_data_addr(g_conf->mlx.img.ptr,
		&g_conf->mlx.img.bpp, &g_conf->mlx.img.line_height,
		&g_conf->mlx.img.endian);
	
}

void	mrt_window_loop()
{
	mrt_mlx_init();
	g_conf->mlx.win = mlx_new_window(g_conf->mlx.ptr,
		g_conf->width, g_conf->height, WINDOW_TITLE);
	mrt_render();
	mrt_update_window();
	mlx_key_hook(g_conf->mlx.win, mrt_key_handler, NULL);
	mlx_loop(g_conf->mlx.ptr);
}
