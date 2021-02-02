/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:43:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 10:55:11 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern	t_conf	*g_conf;

void	mrt_light_ambiant(t_pixel *pixel)
{
	pixel->ray->color = color_multi(pixel->obj->color,
			g_conf->ambient_light.intensity);
	pixel->ray->color = color_add(pixel->ray->color,
			g_conf->al_calculated);
}

void	mrt_light_points(t_pixel *pixel)
{
	t_generic_list	*current;
	t_light			*light;
	t_vector3		light_dir;
	double			light_angle;

	current = g_conf->lights;
	while (current != NULL)
	{
		light = (t_light *)current->obj;
		light_dir = vec3_sub(light->point, pixel->hitpoint);
		light_dir = vec3_normalize(light_dir);
		light_angle = vec3_dot(light_dir, pixel->normal);
		if (light_angle < 0)
			light_angle = 0;
		pixel->ray->color = color_add(
			color_multi(pixel->ray->color, light->brightness),
			color_multi(light->color, light->brightness * light_angle));
		current = current->next;
	}
}