/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:48:22 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/29 22:13:02 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_camera	*camera_new_(t_point3 origin, t_vector3 normal, int fov)
{
	t_camera	*tmp;

	tmp = malloc(sizeof(t_camera));
	tmp->origin = origin;
	tmp->normal = normal;
	tmp->fov = fov;
	return (tmp);
}
