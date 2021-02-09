/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 12:30:21 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

/*
** TODO: Add Screen max size
** FIXME: Free the raw_vals
*/

t_color		mrt_parse_color_valid(char *color)
{
	char	**rgb;

	rgb = ft_split(color, ',');
	if (rgb[0] == NULL || rgb[1] == NULL ||
		rgb[2] == NULL || rgb[3] != NULL)
		mrt_trigger_error(8);
	(ft_strchr(rgb[0], '.') != NULL) ? mrt_trigger_error(9) : NULL; 
	(ft_strchr(rgb[1], '.') != NULL) ? mrt_trigger_error(9) : NULL; 
	(ft_strchr(rgb[2], '.') != NULL) ? mrt_trigger_error(9) : NULL;
	return (color_from_rgb(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2])));
}

void		mrt_parse_resolution(char **key)
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

void	mrt_parse_ambient(char **key)
{
	double	i;
	t_color	c;

	i =	ft_parsefloat(key[1]);
	i > 1 || i < 0 ? mrt_trigger_error(7) : NULL;
	c = mrt_parse_color_valid(key[2]);
	g_conf->ambient_light = ambiant_light_new(i, c.r, c.g, c.b);
	g_conf->al_calculated = color_multi(g_conf->ambient_light.color,
		powf(g_conf->ambient_light.intensity, 2));
}