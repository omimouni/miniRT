/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:53:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 12:56:09 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_parse_square(char **key)
{
	t_point3	p;
	t_vector3	n;
	double		s;
	t_color		c;

	if ((key[1] == NULL) || (key[2] == NULL) || (key[3] == NULL)
		|| (key[4] == NULL) || (key[5] == NULL))
		mrt_trigger_error(15);
	p = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	n = mrt_parse_vec3(key[2], MRT_VEC3_STANDARD);
	mrt_is_double(key[3], 0);
	s = ft_parsefloat(key[3]);
	s <= 0 ? mrt_trigger_error(28) : NULL;
	c = mrt_parse_color_valid(key[4]);
	g_conf->objs = ft_glist_add(g_conf->objs, square_new(p, n, s, c));
}
