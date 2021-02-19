/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:52:32 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 11:52:47 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_parse_triangle(char **key)
{
	t_point3	pa;
	t_point3	pb;
	t_point3	pc;
	t_color		c;

	pa = mrt_parse_vec3(key[1], MRT_VEC3_STANDARD);
	pb = mrt_parse_vec3(key[2], MRT_VEC3_STANDARD);
	pc = mrt_parse_vec3(key[3], MRT_VEC3_STANDARD);
	c = mrt_parse_color_valid(key[4]);
	g_conf->objs = ft_glist_add(g_conf->objs, triangle_new(pa, pc, pb, c));
}
