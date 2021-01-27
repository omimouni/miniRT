/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/27 22:11:08 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

/**
 * @todo Add render progress
 **/

void	mrt_render(unsigned char type)
{
	size_t	i;
	size_t	j;

	printf("< 🖥  Rendering Scene >\n");
	printf("-> 👾 \033[0;32mProgress ...");
	i = 0;
	while (i < g_conf->width)
	{
		j = 0;
		while (j < g_conf->height)
		{
			if (type == MRT_RENDER_WINDOW)
				mrt_put_pixel(i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	printf("\033[0m ✅\n");
	printf("< 🤵 waiting for the next command >\n"); }
