/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:28:19 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/11 11:16:17 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

static char		mrt_light_point_shadow(t_pixel *pixel, t_light *light)
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

static t_color	mrt_light_diffuse(t_pixel *pixel, t_light *light, t_color cq, char add)
{
	t_color	rgb;
	t_color base_color;
	t_color	color_buff;
	double	delta;
	
	base_color = pixel->obj->color;
	if (pixel->is_shadow)
		return (color_from_hex(0xFF0000));
	delta = (cos(light->angle) * vec3_dot(light->dir, pixel->normal) 
	* light->brightness);
	color_buff = color_multi(light->color, delta * 2);
	base_color = color_multi(base_color, delta);
	color_buff = color_add(color_multi(color_buff, light->brightness), 
	color_multi(base_color, .4));
	if (add)
		color_buff = color_add(color_buff, cq);
	return (color_buff);
}

void			mrt_light_points(t_pixel *pixel)
{
	t_generic_list	*current;
	t_light			*light;
	t_color			light_color;
	char			adable;

	current = g_conf->lights;
	adable = 0;
	while (current != NULL)
	{
		light = (t_light *)current->obj;
		light->dir = vec3_sub(light->point, pixel->hitpoint);
		light->distance = vec3_length(light->dir);
		light->dir = vec3_normalize(light->dir);
		light->angle = vec3_dot(light->dir, pixel->normal);
		light->angle = light->angle < 0 ? 0 : light->angle;
		light_color = mrt_light_diffuse(pixel, light, light_color, adable);
		//mrt_light_point_shadow(pixel, light);
		adable = 1;
		current = current->next;
	}
	pixel->ray->color = light_color;
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