/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 16:53:39 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

static	void	mrt_calc_light(t_pixel *pixel)
{
	if (pixel->obj != NULL)
	{
		pixel->ray->color = pixel->obj->color;
		// mrt_light_points(pixel);
		// mrt_light_ambiant(pixel);
	}
	else
		pixel->ray->color = color_from_rgb(0, 0, 0);
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
		tmp_t = INFINITY;
		obj = (t_object *)current->obj;
		if (obj->type == MRT_TYPE_SPHERE)
			tmp_t = mrt_intersect_sphere(ray, obj);
		if (obj->type == MRT_TYPE_PLANE)
			tmp_t = mrt_intersect_plane(ray, obj);
		if (obj->type == MRT_TYPE_CYLINDER)
			tmp_t = mrt_cylinder_intersect(ray, obj);
		if (tmp_t < pixel->t && tmp_t > 0){
			mrt_pixel_update(pixel, tmp_t, ray, obj);
		}
		current = current->next;
	}
	mrt_calc_light(pixel);
	free(pixel);
}
