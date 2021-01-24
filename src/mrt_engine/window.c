/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:41:18 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/24 17:08:25 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

void	mrt_window_loop()
{
	mrt_render();
	mlx_put_image_to_window(g_conf->mlx.ptr, g_conf->mlx.win,
		g_conf->mlx.img.ptr, 0, 0);
	mlx_loop(g_conf->mlx.ptr);
}