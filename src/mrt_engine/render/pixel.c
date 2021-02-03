/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:51:57 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/03 09:30:49 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void		mrt_pixel_update(t_pixel *p, double t, t_mrt_ray *ray,
				t_object *obj)
{
	p->t = t;
	p->ray = ray;
	p->hitpoint = mrt_ray_point(t, ray);
	p->obj = obj;
	if (p->obj->type == MRT_TYPE_SPHERE)
		p->normal = vec3_sub(p->hitpoint, ((t_sphere *)p->obj->object)->center);
	if (p->obj->type == MRT_TYPE_PLANE)
		p->normal = ((t_plane *)p->obj->object)->normal;
	p->normal = vec3_normalize(p->normal);
}

void		mrt_pixel_add_ligh(t_pixel *p, double con)
{
	p->light_cof = con;
}
t_pixel		*pixel_new(double t, t_object *obj, t_mrt_ray *ray)
{
	t_pixel	*tmp;

	tmp = malloc(sizeof(t_pixel));
	tmp->obj = obj;
	tmp->ray = ray;
	tmp->light_cof = 1;
	if (ray != NULL)
		tmp->hitpoint = mrt_ray_point(t, ray);
	tmp->t = t;
	return (tmp);
}
