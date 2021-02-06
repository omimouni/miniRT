/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:25:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 09:56:25 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_maths.h"

t_vector3	vec3_new(double x, double y, double z)
{
	t_vector3	tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

double		vec3_length(t_vector3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector3	vec3_normalize(t_vector3 v)
{
	double	length;

	length = vec3_length(v);
	return (vec3_new(v.x / length, v.y / length, v.z / length));
}

void		vec3_show(t_vector3	v)
{
	printf("V : %f %f %f \n", v.x, v.y, v.z);
}