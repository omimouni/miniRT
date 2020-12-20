/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:10:41 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/20 02:45:30 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*cam_init(t_pt3f *orig, t_vec3f *tar, int fov)
{
	t_cam	*tmp;

	tmp = malloc(sizeof(t_cam));
	tmp->origin = orig;
	tmp->target = tar;
	tmp->fov = fov;
	return (tmp);
}