/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:56:26 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 15:43:27 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

void				bit_insert(unsigned char *ar, int val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ar[i] = (unsigned char)(val >> (8 * i));
		i++;
	}
}

unsigned	char	*bmp_header(void)
{
	unsigned char	*header;

	header = (unsigned char *)ft_calloc(14, sizeof(unsigned char));
	header[0] = 'B';
	header[1] = 'M';
	bit_insert(&header[2], 4 * g_conf->width * g_conf->height + 54);
	header[10] = 54;
	return (header);
}

unsigned char		*bmp_header_info(void)
{
	unsigned char	*header;

	header = (unsigned char *)ft_calloc(40, sizeof(unsigned char));
	header[0] = 40;
	bit_insert(&header[4], g_conf->width);
	bit_insert(&header[8], g_conf->height);
	header[12] = 1;
	header[14] = 24;
	bit_insert(&header[20], 4 * g_conf->width * g_conf->height);
	bit_insert(&header[24], 72 * (int)(39.375));
	bit_insert(&header[28], 72 * (int)(39.375));
	return (header);
}