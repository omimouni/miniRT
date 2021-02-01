/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:54 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 10:00:09 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

void static mrt_quit()
{
	mlx_clear_window(g_conf->mlx.ptr, g_conf->mlx.win);
	mlx_destroy_image(g_conf->mlx.ptr, g_conf->mlx.img.ptr);
	mlx_destroy_window(g_conf->mlx.ptr, g_conf->mlx.win);
	printf("< 👋  Quitting ! > \n");
	exit(0);
}

void static	mrt_next_cam()
{
}

int	mrt_key_handler(int keycode)
{
	// printf("%d\n", keycode);
	if (keycode == MRT_KEY_NUM5)
		mrt_next_cam();
	if (keycode == MRT_KEY_ESC)
		mrt_quit();
	return (0);
}
