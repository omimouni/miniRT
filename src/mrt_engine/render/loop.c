/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:40:21 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 00:08:02 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void				mrt_menu_strings()
{
	mrt_put_string("4:L", g_conf->width * .86 + 3, g_conf->height * .9 + 30);
	mrt_put_string("6:R", g_conf->width * .86 + 43, g_conf->height * .9 + 30);
	mrt_put_string("2:D", g_conf->width * .86 + 23, g_conf->height * .9 + 45);
	mrt_put_string("8:T", g_conf->width * .86 + 23, g_conf->height * .9 + 14);

	if (g_conf->is_ambient)
		mrt_put_string("1- disable ambient light", g_conf->width * .65 + 5, g_conf->height * .75 + 17);
	else
		mrt_put_string("1- enable ambient light", g_conf->width * .65 + 5, g_conf->height * .75 + 17);
	mrt_put_string("5- switch camera", g_conf->width * .65 + 5, g_conf->height * .75 + 32);
}

char				mrt_is_menu(int i, int j)
{
	if (i >= g_conf->width * .65 && j >= g_conf->height * .75)
		return (1);
	return (0);
}
void				mrt_put_string(char *str, int x, int y)
{
	mlx_string_put(g_conf->mlx.ptr, g_conf->mlx.win, x, y, 0xFFFFFF, str);
}

void				mrt_render_loop(size_t swidth, size_t width,
	size_t sheight, size_t height)
{
	size_t		i;
	size_t		j;
	t_mrt_ray	*ray;

	width = ft_clamp_int(width, 0, g_conf->width);
	height = ft_clamp_int(height, 0, g_conf->height);
	ray = mrt_ray_init(mrt_current_camera()->origin);
	i = swidth;
	printf("%ld %ld \n", width, height);
	while (i < width)
	{
		j = sheight;
		while (j < height)
		{
			if (mrt_is_menu(i, j))
				mrt_put_pixel(i, j, color_from_rgb(0, 0, 0));
			else {
				mrt_ray_update(&ray, i, j);
				mrt_raytrace(ray);
				if (g_conf->is_save)
					continue;
				else
					mrt_put_pixel(i, j, ray->color);
			}
			j++;
		}
		i++;
	}
	// MENU
	// mrt_menu_side();
	mrt_update_window();
	mrt_menu_strings();
	free(ray);
}
