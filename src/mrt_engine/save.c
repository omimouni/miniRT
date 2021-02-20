/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:24:39 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 16:38:14 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

void	mrt_save_image(void)
{
	int				fd;
	unsigned char	*color[3];
	char			*filename;
	unsigned char	*hrds[2];
	int				x;
	int				y;

	mrt_img_init();
	g_conf->current_camera = g_conf->cameras;
	camera_calc(mrt_current_camera());
	mrt_render();
	filename = ft_strjoin(WINDOW_TITLE, ".bmp");
	fd = open(filename, O_CREAT | O_WRONLY, 777);
	hrds[0] = bmp_header();
	hrds[1] = bmp_header();
	write(fd, hrds[0], 14);
	write(fd, hrds[1], 40);
	y = g_conf->height + 1;
	while (y-- > 0)
	{
		x = g_conf->width * y - g_conf->width;
		while (x < (int)g_conf->width * y)
		{
			bit_insert((unsigned char *)color, 0xFF0000);
			write(fd, color, 3);
			x++;
		}
	}
	free(hrds[0]);
	free(hrds[1]);
	free(filename);
	close(fd);
	mrt_quit();
}
