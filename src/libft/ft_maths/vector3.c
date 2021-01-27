/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:25:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/27 16:19:16 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

t_vector3	vec3_new(double x, double y, double z)
{
	t_vector3	tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

t_vector3	vec3_add(t_vector3 v, t_vector3 w)
{
	t_vector3	tmp;

	tmp.x = v.x + w.x;
	tmp.y = v.y + w.y;
	tmp.z = v.z + v.z;
	return (tmp);
}
