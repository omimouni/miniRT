/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 04:11:59 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/19 04:18:52 by omimouni         ###   ########.fr       */
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