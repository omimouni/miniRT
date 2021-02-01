/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 15:26:11 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

static	void	mrt_calc_light(t_pixel *p)
{

}

void			mrt_raytrace(t_mrt_ray *ray)
{
	t_generic_list	*current;
	t_object		*obj;
	t_pixel			*pixel;
	double			tmp_t;

	current = g_conf->objs;
	pixel = pixel_new(INFINITY, NULL, NULL);
	while (current != NULL)
	{
		obj = (t_object *)current->obj;
		// Calculate the hitpoint
		if (obj->type == MRT_TYPE_SPHERE)
			tmp_t = mrt_intersect_sphere(ray, obj);
		// Replace pixel with closest object
		if (tmp_t < pixel->t)
			mrt_pixel_update(pixel, tmp_t, ray, obj);
		current = current->next;
	}
	// LET THERE BE LIGHT
	if (pixel->obj != NULL)
		ray->color = hex_from_color(pixel->obj->color);
	else
		ray->color = 0x00000;
	free(pixel);
}
