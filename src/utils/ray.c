/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:13:43 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 03:13:55 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_ray3f		*ray3f_new(t_vec3f *p, t_vec3f *d)
{
	t_ray3f	*tmp;

	tmp = malloc(sizeof(t_ray3f));
	tmp->start = p;
	tmp->dir = d;
	return (tmp);
}

void		ray3f_free(t_ray3f *r)
{
	free(r->start);
	free(r->dir);
	free(r);
}
