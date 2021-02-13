/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/13 10:22:37 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	printcolor(char *pre, t_color c)
{
	printf("%s %d %d %d \n",pre, c.r, c.g, c.b);
}

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

static void		mrt_light_points_2(t_pixel *p)
{
	t_generic_list	*current;
	t_light			*light;

	current = g_conf->lights;
	while (current != NULL)
	{
		light = (t_light *)current->obj;
		light->dir = vec3_sub(light->point, p->hitpoint);
		light->distance = vec3_length(light->dir);
		light->dir = vec3_normalize(light->dir);
		light->angle = vec3_dot(light->dir, p->normal);
		light->angle = light->angle < 0 ? 0 : light->angle;
		p->ray->color = mrt_light_diffuse(p, light);
		current = current->next;
	}
}

static void		mrt_calc_light(t_pixel *pixel)
{
	pixel->ray->color = color_from_rgb(0, 0, 0);
	if (pixel->obj != NULL)
	{
		// if (g_conf->is_bonus)
		// {
		// 	pixel->obj->type == MRT_TYPE_SPHERE ? mrt_uv_sphere(pixel) : NULL;
		// 	pixel->obj->type == MRT_TYPE_PLANE ? mrt_uv_plane(pixel) : NULL;
		// }
		if (g_conf->is_ambient)
		{
			mrt_light_points_2(pixel);
			// mrt_light_points(pixel);
			// mrt_light_ambiant(pixel);
		}
	}
}

static double	mrt_ray_switch(t_object *obj, t_mrt_ray *ray, t_pixel *p)
{
	double	tmp_t;

	tmp_t = INFINITY;
	if (obj->type == MRT_TYPE_SPHERE)
		tmp_t = mrt_intersect_sphere(ray, obj);
	if (obj->type == MRT_TYPE_PLANE)
		tmp_t = mrt_intersect_plane(ray, obj);
	if (obj->type == MRT_TYPE_CYLINDER)
		tmp_t = mrt_cylinder_intersect(ray, obj);
	if (obj->type == MRT_TYPE_TRIANGLE)
		tmp_t = mrt_triangle_intersection(ray, obj);
	if (obj->type == MRT_TYPE_SQUARE)
		tmp_t = mrt_square_intersection(ray, obj);
	if (tmp_t < p->t && tmp_t > 0)
		mrt_pixel_update(p, tmp_t, ray, obj);
	return (tmp_t);
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
		tmp_t = mrt_ray_switch(obj, ray, pixel);
		current = current->next;
	}
	mrt_calc_light(pixel);
	free(pixel);
}
