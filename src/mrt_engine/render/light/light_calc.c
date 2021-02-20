/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:28:19 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 17:23:24 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

static t_color	mrt_light_diffuse(t_pixel *p, t_light *light)
{
	double	delta;
	t_color	color;
	t_color base_color;

	delta = cos(light->angle) * light->angle * light->brightness;
	base_color = p->obj->color;
	base_color = color_multi(base_color, delta);
	color = color_multi(light->color, delta);
	color = color_add(base_color, color);
	color = color_add(p->ray->color, color);
	return (color);
}

void			mrt_light_point_shadow(t_pixel *pixel, t_light *light)
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
		else if (obj->type == MRT_TYPE_SQUARE)
			light->angle = mrt_square_cast_shadow(pixel, obj, light);
		else if (obj->type == MRT_TYPE_TRIANGLE)
			light->angle = mrt_triangle_cast_shadow(pixel, obj, light);
		current = current->next;
	}
}

void			mrt_light_points(t_pixel *p)
{
	t_generic_list	*current;
	t_light			*light;

	current = g_conf->lights;
	p->light_cof = 0;
	while (current != NULL)
	{
		light = (t_light *)current->obj;
		light->dir = vec3_sub(light->point, p->hitpoint);
		light->distance = vec3_length(light->dir);
		light->dir = vec3_normalize(light->dir);
		light->angle = vec3_dot(light->dir, p->normal);
		if (p->obj->type != MRT_TYPE_CYLINDER)
			light->angle = light->angle < 0 ? 0 : light->angle;
		else
			light->angle = 1;
		p->light_cof += light->angle;
		mrt_light_point_shadow(p, light);
		p->ray->color = mrt_light_diffuse(p, light);
		current = current->next;
	}
}

void			mrt_light_ambiant(t_pixel *pixel)
{
	t_color	c_color;

	c_color = color_multi(g_conf->ambient_light.color,
				g_conf->ambient_light.intensity / 2);
	pixel->ray->color = color_add(c_color, pixel->ray->color);
}
