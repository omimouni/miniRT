/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/27 17:20:09 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

/**
 * @todo Add render progress
 **/

void static		show_progress(size_t i, size_t j)
{
	size_t	progress;

	progress = g_conf->height * g_conf->width;
	i++;
	j++;
	printf("\r\033[0;32m👾 Progress: %ld%%\033[0m",((i * j) / progress) * 100);
}

void	mrt_render(unsigned char type)
{
	size_t	i;
	size_t	j;

	printf("\n* 🖥  Rendering Scene \n");
	i = 0;
	while (i < g_conf->width)
	{
		j = 0;
		while (j < g_conf->height)
		{
			show_progress(i, j);
			if (type == MRT_RENDER_WINDOW)
				mrt_put_pixel(i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	printf("\n🌚 Done\n");
	printf("\n* 🤵  waiting for the next command. \n");
}
