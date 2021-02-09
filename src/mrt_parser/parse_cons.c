/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 11:22:18 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

/*
** TODO: Add Screen max size
*/

void	parse_resolution(char **key)
{
	double	width;
	double	height;

	width = ft_atoi(key[1]);
	height = ft_atoi(key[2]);

	if (width == 0)
		mrt_trigger_error(4);
	if (height == 0)
		mrt_trigger_error(5);
	if (ft_strchr(key[1], '.') || ft_strchr(key[2], '.'))
		mrt_trigger_error(6);
	g_conf->width = width;
	g_conf->height = height;
}

void	parse_ambient(char **key)
{
	printf("D: %f %s \n", ft_parsefloat(key[1]), key[1]);
}