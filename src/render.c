/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:39:09 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 03:15:56 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_conf *conf)
{
	size_t	i;
	size_t	j;
	t_cam	*cam;
	t_ray3f	*ray;
	double	h_canvas;
	double	w_canvas;

	// Generating the camera ---
	cam = cam_init(vec3f_new(0, 0, 0), vec3f_new(0, 0, -1), 90);
	h_canvas = atan(cam->fov);
	w_canvas = cam->r * h_canvas;

	// Generate Image ---
	i = 0;
	while (i < 700)
	{
		j = 0;
		while (j < 500)
		{
			j++;
		}
		i++;
	}
}
