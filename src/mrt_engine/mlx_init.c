/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:41:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/24 20:29:58 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

void	mrt_mlx_init(void)
{
	g_conf->mlx.ptr = mlx_init();
	g_conf->mlx.img.ptr = mlx_new_image(g_conf->mlx.ptr,
		g_conf->width, g_conf->height);
	g_conf->mlx.img.addr = mlx_get_data_addr(g_conf->mlx.img.ptr,
		&g_conf->mlx.img.bpp, &g_conf->mlx.img.line_height,
		&g_conf->mlx.img.endian);
	
}