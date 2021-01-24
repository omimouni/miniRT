/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:10:16 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/24 21:40:53 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_mrt_camera	*camera_new(t_point3 origin, t_vector3 normal, int fov)
{
	t_mrt_camera	*camera;

	camera = malloc(sizeof(t_mrt_camera));
	camera->origin = origin;
	camera->normal = normal;
	camera->fov = fov;
	return (camera);
}

