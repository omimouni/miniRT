/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:56:26 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 14:52:05 by omimouni         ###   ########.fr       */
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

	header = malloc(sizeof(unsigned char) * 14);
	header[0] = 'B';
	header[1] = 'M';
	bit_insert(&header[2], 4 * g_conf->width * g_conf->height + 54);
	header[10] = 54;
	return (header);
}