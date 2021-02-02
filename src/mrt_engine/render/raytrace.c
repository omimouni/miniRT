/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 09:51:08 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

static	void	mrt_calc_light(t_pixel *pixel)
{
	t_generic_list	*current;
	t_light			*light;
	t_vector3		light_dir;
	double			light_angle;

	if (pixel->obj != NULL)
	{
		pixel->ray->color = color_multi(pixel->obj->color,
			g_conf->ambient_light.intensity);
		pixel->ray->color = color_add(pixel->ray->color,
			g_conf->al_calculated);
		// Light point ------
		current = g_conf->lights;
		while (current != NULL)
		{
			light = (t_light *)current->obj;
			light_dir = vec3_sub(light->point, pixel->hitpoint);
			light_angle = vec3_dot(light_dir, pixel->normal);
			if (light_angle < 0)	light_angle = 0;
			pixel->ray->color = color_add(pixel->ray->color, color_add(color_multi(pixel->obj->color,
			light->brightness * light_angle), color_multi(light->color, light_angle * light->brightness)));
			current = current->next;
		}
	}
	else
		pixel->ray->color = color_from_rgb(0, 0, 0);
	free(pixel);
}

void			mrt_raytrace(t_mrt_ray *ray)
{
	t_generic_list	*current;
	t_object		*obj;
	t_pixel			*pixel;
	double			tmp_t;

	current = g_conf->objs;
	pixel = pixel_new(INFINITY, NULL, ray);
	while (current != NULL)
	{
		obj = (t_object *)current->obj;
		if (obj->type == MRT_TYPE_SPHERE)
			tmp_t = mrt_intersect_sphere(ray, obj);
		if (tmp_t < pixel->t)
			mrt_pixel_update(pixel, tmp_t, ray, obj);
		current = current->next;
	}
	mrt_calc_light(pixel);
}
