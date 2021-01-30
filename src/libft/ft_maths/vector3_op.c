/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:25:36 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/30 12:40:13 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

t_vector3	vec3_add(t_vector3 v, t_vector3 w)
{
	t_vector3	tmp;

	tmp.x = v.x + w.x;
	tmp.y = v.y + w.y;
	tmp.z = v.z + v.z;
	return (tmp);
}

t_vector3	vec3_sub(t_vector3 v, t_vector3 w)
{
	t_vector3	tmp;

	tmp.x = v.x - w.x;
	tmp.y = v.y - w.y;
	tmp.z = v.z - w.z;
	return (tmp);
}

t_vector3	vec3_mult(double n, t_vector3 v)
{
	t_vector3	tmp;

	tmp.x = n * v.x;
	tmp.y = n * v.y;
	tmp.z = n * v.z;
	return (tmp);
}

t_vector3	vec3_cross(t_vector3 v, t_vector3 w)
{
	t_vector3	tmp;

	tmp.x = v.y * w.z - v.z * w.y;
	tmp.y = v.z * w.x - v.x * w.z;
	tmp.z = v.x * w.y - v.y * w.x;
	return (tmp);
}

double		vec3_dot(t_vector3 v, t_vector3 w)
{
	return (v.x * v.x + v.y * w.y + v.z * w.z);
}
