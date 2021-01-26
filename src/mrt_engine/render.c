/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/25 22:36:39 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

/**
 * @todo Add render progress
 **/

void	mrt_render(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("Rendering Scene ...");
	while (i < g_conf->width)
	{
		j = 0;
		while (j < g_conf->height)
		{
			mrt_put_pixel(i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	printf(" Done\n");
}
