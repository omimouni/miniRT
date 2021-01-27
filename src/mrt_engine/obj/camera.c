/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:15:19 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/27 22:20:54 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_mrt_camera	*mrt_camera_new(t_point3 origin, t_vector3 normal, int fov)
{
	t_mrt_camera	*tmp;

	tmp = malloc(sizeof(t_mrt_camera));
	tmp->origin = origin;
	tmp->normal = normal;
	tmp->fov = fov;
	return (tmp);
}
