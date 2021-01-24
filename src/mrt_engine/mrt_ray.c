/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:31:34 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/24 17:35:34 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_mrt_ray	*mrt_ray_init(t_point3 orig, t_vector3 dir)
{
	t_mrt_ray	*ray;

	ray->origin = orig;
	ray->direction = dir;
	return (ray);
}

void	mrt_ray_free(t_mrt_ray *ray)
{
	free(ray);
}