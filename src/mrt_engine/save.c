/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:24:39 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 23:19:46 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

static int		mrt_save_filename(void)
{
	char	*filename;
	int		fd;

	filename = ft_strjoin(WINDOW_TITLE, ".bmp");
	fd = open(filename, O_CREAT | O_WRONLY, 777);
	free(filename);
	return (fd);
}

static void		mrt_save_loop(int fd)
{
	int				*image;
	size_t			x;
	size_t			y;
	unsigned char	*color[3];

	image = ((int *)g_conf->mlx.img.addr);
	y = g_conf->height + 1;
	while (y-- > 0)
	{
		x = g_conf->width * y - g_conf->width;
		while (x < g_conf->width * y)
		{
			bit_insert((unsigned char *)color, image[x]);
			write(fd, color, 3);
			x++;
		}
	}
}

void			mrt_save_image(void)
{
	int				fd;
	unsigned char	*hrds[2];

	mrt_img_init();
	g_conf->current_camera = g_conf->cameras;
	camera_calc(mrt_current_camera());
	mrt_render();
	fd = mrt_save_filename();
	hrds[0] = bmp_header();
	hrds[1] = bmp_header_info();
	write(fd, hrds[0], 14);
	write(fd, hrds[1], 40);
	free(hrds[0]);
	free(hrds[1]);
	mrt_save_loop(fd);
	close(fd);
	mrt_quit();
}
