/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:41:18 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/05 14:36:15 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

void	mrt_update_window(void)
{
	mlx_put_image_to_window(g_conf->mlx.ptr, g_conf->mlx.win,
		g_conf->mlx.img.ptr, 0, 0);
}

void	mrt_mlx_init(void)
{
	g_conf->mlx.ptr = mlx_init();

}

void	mrt_window_loop(void)
{
	mrt_mlx_init();
	g_conf->current_camera = g_conf->cameras;
	g_conf->mlx.win = mlx_new_window(g_conf->mlx.ptr,
		g_conf->width, g_conf->height, WINDOW_TITLE);
	camera_calc(mrt_current_camera());
	mrt_render();
	mrt_update_window();
	mrt_hooks();
	// exit(0);
	mlx_loop(g_conf->mlx.ptr);
}
