/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 15:09:58 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

static	void	mrt_calc_light(t_pixel *pixel)
{
	t_generic_list	*current;
	t_light			*light;
	t_vector3		light_dir;
	t_color			buffer;
	double			light_angle;

	
	if (pixel->obj != NULL)
	{
		// mrt_light_ambiant(pixel);
		// mrt_light_points(pixel);
		pixel->ray->color = pixel->obj->color;
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
		obj = (t_object *)current->obj;
		if (obj->type == MRT_TYPE_SPHERE)
			tmp_t = mrt_intersect_sphere(ray, obj);
		if (tmp_t < pixel->t && tmp_t > 0)
			mrt_pixel_update(pixel, tmp_t, ray, obj);
		current = current->next;
	}
	mrt_calc_light(pixel);
}
