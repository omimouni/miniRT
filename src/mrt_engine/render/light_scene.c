/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:43:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 18:47:48 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern	t_conf	*g_conf;

void	mrt_light_ambiant(t_pixel *pixel)
{
	t_color	color;

	color = color_add(g_conf->al_calculated, color_multi(pixel->obj->color,
		g_conf->ambient_light.intensity));
	pixel->ray->color = color_add(color_multi(pixel->ray->color, 1), color);
	// pixel->ray->color = color_multi(pixel->obj->color,
	// 		g_conf->ambient_light.intensity);
	// pixel->ray->color = color_add(pixel->ray->color,
	// 		g_conf->al_calculated);
}

void	mrt_light_points(t_pixel *pixel)
{
	t_generic_list	*current;
	t_light			*light;
	current = g_conf->lights;
	while (current != NULL)
	{
		light = (t_light *)current->obj;
		light->point = mrt_current_camera()->origin;
		light->dir = vec3_sub(pixel->hitpoint, light->point);
		light->distance = vec3_length(light->dir);
		light->dir = vec3_normalize(light->dir);
		light->angle = vec3_dot(light->dir, pixel->normal);
		if (light->angle < 0)
			light->angle = 0;
		if (light->angle) printf("%f \n", light->angle);
		pixel->ray->color = color_multi(pixel->obj->color,
			light->angle * light->brightness / (double)(light->distance * light->distance));
		// pixel->ray->color = color_multi(pixel->obj->color, 1);
		current = current->next;
	}
}