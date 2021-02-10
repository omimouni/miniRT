/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:28:19 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/10 11:49:32 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		else if (obj->type == MRT_TYPE_CYLINDER)
			light->angle = mrt_cylinder_cast_shadow(pixel, obj, light);
		current = current->next;
	}
}

static t_color	mrt_light_diffuse(t_pixel *pixel, t_light *light, t_color c)
{
	t_color	rgb;
	t_color color;
	t_color	color_buff;

	rgb = color_multi(c, ((light->brightness / 2) + 
	(light->distance / light->angle)));
	rgb = color_add(rgb, color_multi(light->color, 
	light->brightness * light->angle / (light->distance + .1)));
	return (rgb);
}

void			mrt_light_points(t_pixel *pixel)
{
	t_generic_list	*current;
	t_light			*light;
	t_color			c;

	current = g_conf->lights;
	c = pixel->obj->color;
	while (current != NULL)
	{
		light = (t_light *)current->obj;
		light->dir = vec3_sub(light->point, pixel->hitpoint);
		light->distance = vec3_length(light->dir);
		light->dir = vec3_normalize(light->dir);
		light->angle = vec3_dot(light->dir, pixel->normal);
		light->angle = light->angle < 0 ? 0 : light->angle;
		mrt_light_point_shadow(pixel, light);
		c = mrt_light_diffuse(pixel, light, c);
		current = current->next;
	}
	pixel->ray->color = c;
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