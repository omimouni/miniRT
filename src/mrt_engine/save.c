/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:24:39 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/18 22:43:32 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

void	mrt_save_image(void)
{
	mrt_img_init();
	g_conf->current_camera = g_conf->cameras;
	camera_calc(mrt_current_camera());

	// Generate BMP File
	int	fd;
	char	*filename;

	filename = ft_strjoin(WINDOW_TITLE, ".bmp");
	fd = open(filename, O_RDWR | O_CREAT, 777);
	// Print file

	// Print pixels
	mrt_render();

	free(filename);
	close(fd);
	//End of line
	mrt_quit();
}
