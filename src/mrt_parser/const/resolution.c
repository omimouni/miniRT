/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:35:22 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 11:41:03 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

void		mrt_parse_resolution(char **key)
{
	double	width;
	double	height;

	if (g_conf->res_parsed)
		mrt_trigger_error(18);
	if ((key[1] == NULL) || (key[2] == NULL) || (key[3] != NULL))
		mrt_trigger_error(15);
	mrt_is_integer(key[1], 0);
	mrt_is_integer(key[2], 0);
	width = ft_atoi(key[1]);
	height = ft_atoi(key[2]);
	width = ft_clamp_int(width, 0, 2600);
	height = ft_clamp_int(height, 0, 1600);
	if (width < 0 || height < 0)
		mrt_trigger_error(16);
	if (width == 0)
		mrt_trigger_error(4);
	if (height == 0)
		mrt_trigger_error(5);
	if (ft_strchr(key[1], '.') || ft_strchr(key[2], '.'))
		mrt_trigger_error(6);
	g_conf->width = width;
	g_conf->height = height;
	g_conf->res_parsed = 1;
}
