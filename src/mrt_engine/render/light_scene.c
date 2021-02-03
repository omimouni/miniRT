/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:43:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/03 02:54:26 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern	t_conf	*g_conf;

void	mrt_light_ambiant(t_pixel *pixel)
{
	t_color	c_color; // Current color
	t_color	color;

	c_color = color_multi(pixel->ray->color, .2);
	c_color = color_add(c_color, g_conf->al_calculated);
	c_color = color_add(c_color, color_multi(pixel->ray->color, .9));
	pixel->ray->color = c_color;
}

void	mrt_light_points(t_pixel *pixel)
{
	t_generic_list	*current;
	t_color			color;
	t_light			*light;

	current = g_conf->lights;
	while (current != NULL)
	{
		light = (t_light *)current->obj;
		light->dir = vec3_sub(light->point, pixel->hitpoint);
		light->distance = vec3_length(light->dir);
		light->dir = vec3_normalize(light->dir);
		light->angle = vec3_dot(light->dir, pixel->normal);
		if (light->angle < 0)
			light->angle = 0;
		color = color_multi(light->color, (.4 * light->angle * (light->brightness * 6)) / (powf(light->distance, 1)));
		
		pixel->ray->color = color_multi(pixel->obj->color, ( .6 * (light->angle 
			* (light->brightness * 6))) / (powf(light->distance, 1)));
		pixel->ray->color = color_add(pixel->ray->color, color);
		current = current->next;
	}
}