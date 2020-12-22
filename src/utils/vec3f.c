/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 04:11:59 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 01:28:41 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec3f	*vec3f_new(double x, double y, double z)
{
	t_vec3f	*tmp;

	tmp = malloc(sizeof(t_vec3f));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	return (tmp);
}

t_vec3f	*vec3f_add(t_vec3f *v, t_vec3f *w)
{
	return (vec3f_new(v->x + w->x, v->y + w->y, v->z + w->z));
}

t_vec3f	*vec3f_sub(t_vec3f *v, t_vec3f *w)
{
	return (vec3f_new(v->x - w->x, v->y - w->y, v->z - w->z));
}

t_vec3f	*vec3f_scalar(double n, t_vec3f *v)
{
	return (vec3f_new(n * v->x, n * v->y, n * v->z));
}

double	vec3f_length(t_vec3f *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec3f	*vec3f_cross(t_vec3f *v, t_vec3f *w)
{
	return (vec3f_new(
		v->y * w->z - v->z * w->y,
		v->z * w->x - v->x * w->z,
		v->x * w->y - v->y * w->x));
}

t_vec3f	*vec3f_normalize(t_vec3f *v)
{
	double	leng;

	leng = vec3f_length(v);
	return (vec3f_new(v->x / leng, v->y / leng, v->z / leng));
}

void	vec3f_free(t_vec3f *v)
{
	free(v);
}
