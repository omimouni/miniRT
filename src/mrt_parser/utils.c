/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:42:29 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 15:43:50 by omimouni         ###   ########.fr       */
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
	return (tmp);
}

t_color		mrt_parse_color_valid(char *color)
{
	char	**rgb;

	rgb = ft_split(color, ',');
	if (ISN(rgb[0]) || ISN(rgb[1]) || ISN(rgb[2]) || !ISN(rgb[3]))
		mrt_trigger_error(8);
	(ft_strchr(rgb[0], '.') != NULL) ? mrt_trigger_error(9) : NULL; 
	(ft_strchr(rgb[1], '.') != NULL) ? mrt_trigger_error(9) : NULL; 
	(ft_strchr(rgb[2], '.') != NULL) ? mrt_trigger_error(9) : NULL;
	return (color_from_rgb(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2])));
}