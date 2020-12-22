/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:39:09 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 05:39:45 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_conf *conf)
{
	size_t	i;
	size_t	j;

	t_pt3f	*orig;
	t_vec3f	*target;
	t_cam	*cam;
	
	double	h_canvas;
	double	w_canvas;
	double x;
	double y;

	// Generating the camera ---
	cam = cam_init(vec3f_new(0, 0, 0), vec3f_new(0, 0, 0), 90, conf);
	h_canvas = atan(cam->fov);
	w_canvas = cam->r * h_canvas;

	// Generate Image ---
	i = 0;
	while (i < conf->width)
	{
		j = 0;
		while (j < conf->height)
		{
			x = cam_pixel_x(i, cam, conf);
			y = cam_pixel_x(j, cam, conf);
			j++;
		}
		i++;
	}
}
