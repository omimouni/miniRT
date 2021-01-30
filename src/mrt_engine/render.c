/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/30 10:28:52 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

/**
 * @todo Add render progress
 **/

void static	mrt_render_loop()
{
	size_t	i;
	size_t	j;
	int		color;

	i = 0;
	while (i < g_conf->width)
	{
		j = 0;
		while (j < g_conf->height)
		{
			color = 0x00000000;
			if (g_conf->is_save)
				// @todo: add bmp renderer
				continue;
			else
				mrt_put_pixel(i, j, color);
			j++;
		}
		i++;
	}
}

void	mrt_render()
{
	printf("< 🖥  Rendering Scene >\n");
	printf("-> 👾 \033[0;32mProgress ...");
	mrt_render_loop();
	printf("\033[0m ✅\n");
	printf("< 🤵 waiting for the next command >\n");
}
