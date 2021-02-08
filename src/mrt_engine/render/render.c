/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 21:08:52 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_render(void)
{
	if (g_conf->is_render)
		mlx_destroy_image(g_conf->mlx.ptr, g_conf->mlx.img.ptr);
	g_conf->mlx.img.ptr = mlx_new_image(g_conf->mlx.ptr,
	g_conf->width, g_conf->height);
	g_conf->mlx.img.addr = mlx_get_data_addr(g_conf->mlx.img.ptr,
		&g_conf->mlx.img.bpp, &g_conf->mlx.img.line_height,
		&g_conf->mlx.img.endian);
	printf("🖥  Rendering Scene\n");
	printf("👾 \033[0;32mProgress ...");
	mrt_render_loop(0, g_conf->width, 0, g_conf->height);
	printf("\033[0m ✅\n");
	printf("\n🤵 waiting for the next command\n");
	g_conf->is_render = 1;
}
