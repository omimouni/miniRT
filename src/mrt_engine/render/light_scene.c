/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:43:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 15:22:35 by omimouni         ###   ########.fr       */
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

	current = g_conf->lights;
	while (current != NULL)
	{
		
		current = current->next;
	}
}