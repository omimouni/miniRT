/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:43:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/04 23:15:27 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern	t_conf	*g_conf;

static void		mrt_light_point_shadow(t_pixel *pixel, t_light *light)
{
	t_object		*obj;
	t_generic_list	*current;

	current = g_conf->objs;
	while (current != NULL)
	{
		obj = (t_object *)current->obj;
		if (obj->type == MRT_TYPE_SPHERE)
			light->angle = mrt_sphere_cast_shadow(pixel, obj, light);
		else if (obj->type == MRT_TYPE_PLANE)
			light->angle = mrt_plane_cast_shadow(pixel, obj, light);
		current = current->next;
	}
}

static void		mrt_light_point_calc(t_pixel *pixel)
{
	t_generic_list	*current;
	t_light			*light;
	t_color			color;

	current = g_conf->lights;
	while (current != NULL)
	{
		light = (t_light *)current->obj;
		// light->point = ((t_camera *)g_conf->cameras->obj)->origin;
		light->dir = vec3_sub(light->point, pixel->hitpoint);
		light->distance = vec3_length(light->dir);
		light->dir = vec3_normalize(light->dir);
		light->angle = vec3_dot(light->dir, pixel->normal);
		if (light->angle < 0)
			light->angle = 0;
		mrt_light_point_shadow(pixel, light);
		color = color_multi(light->color, (.4 * light->angle *
			(light->brightness * 6)) / (powf(light->distance, 1)));
		pixel->ray->color = color_multi(pixel->obj->color, (.6 * (light->angle
			* (light->brightness * 6))) / (powf(light->distance, 1)));
		pixel->ray->color = color_add(pixel->ray->color, color);
		pixel->light_cof = light->angle;
		current = current->next;
	}
}

void			mrt_light_ambiant(t_pixel *pixel)
{
	t_color	c_color;
	t_color	color;

	if (pixel->light_cof < .1)
		c_color = color_multi(pixel->obj->color, pixel->light_cof * .1);
	else
		c_color = color_multi(pixel->ray->color, .4);
	c_color = color_add(c_color, g_conf->al_calculated);
	c_color = color_add(c_color, color_multi(pixel->ray->color, .5));
	pixel->ray->color = c_color;
}

void			mrt_light_points(t_pixel *pixel)
{
	pixel->ray->color = pixel->obj->color;
	mrt_light_point_calc(pixel);
}
