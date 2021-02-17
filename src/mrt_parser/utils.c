/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:42:29 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/17 08:41:07 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	mrt_parse_vec3(char *cord, char type)
{
	char		**key;
	t_vector3	tmp;

	key = ft_split(cord, ',');
	if (key[0] == NULL || key[1] == NULL ||
		key[2] == NULL || key[3] != NULL)
		mrt_trigger_error(11);
	tmp.x = ft_parsefloat(key[0]);	
	tmp.y = ft_parsefloat(key[1]);	
	tmp.z = ft_parsefloat(key[2]);
	if (type == MRT_VEC3_NORMALIZED && vec3_length(tmp) != 1)
		mrt_trigger_error(12);
	free_split(key);
	return (tmp);
}

t_color		mrt_parse_color_valid(char *color)
{
	char	**rgb;
	t_color	c;

	rgb = ft_split(color, ',');
	if ((rgb[0] == NULL) || (rgb[1] == NULL) || 
	(rgb[2] == NULL) || (rgb[3] != NULL))
		mrt_trigger_error(8);
	mrt_has_alphabet(rgb[0]);
	mrt_has_alphabet(rgb[1]);
	mrt_has_alphabet(rgb[2]);
	(ft_strchr(rgb[0], '.') != NULL) ? mrt_trigger_error(9) : NULL; 
	(ft_strchr(rgb[1], '.') != NULL) ? mrt_trigger_error(9) : NULL; 
	(ft_strchr(rgb[2], '.') != NULL) ? mrt_trigger_error(9) : NULL;
	c.r = ft_atoi(rgb[0]);
	c.g = ft_atoi(rgb[1]);
	c.b = ft_atoi(rgb[2]);
	if ((c.r > 255 || c.r < 0) || (c.g > 255 || c.g < 0)
		|| (c.b > 255 || c.b < 0))
		mrt_trigger_error(8);
	free_split(rgb);
	return (color_from_rgb(c.r, c.g, c.b));
}
