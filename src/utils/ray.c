/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:13:43 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/20 02:20:43 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_ray3f 	*ray3f_new(double x, double y, double z, t_vec3f *d)
{
	t_ray3f	*tmp;

	tmp = malloc(sizeof(t_ray3f));
	tmp->start = vec3f_new(x, y, z);
	tmp->dir = d;
	return (tmp);
}

void	ray3f_free(t_ray3f *r)
{
	free(r->start);
	free(r->dir);
	free(r);
}