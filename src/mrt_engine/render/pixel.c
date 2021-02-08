/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:51:57 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 16:58:23 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		mrt_pixel_update(t_pixel *p, double t, t_mrt_ray *ray,
				t_object *obj)
{
	p->t = t;
	// IF YOU STUCK YOU DID REMOVE p->ray = ray FROM HERE RETARD.
	p->hitpoint = mrt_ray_point(t, ray);
	p->obj = obj;
	if (p->obj->type == MRT_TYPE_SPHERE)
		p->normal = vec3_sub(p->hitpoint, ((t_sphere *)p->obj->object)->center);
	else if (p->obj->type == MRT_TYPE_PLANE)
		p->normal = ((t_plane *)p->obj->object)->normal;
	else if (p->obj->type == MRT_TYPE_CYLINDER)
		p->normal = mrt_cylinder_normal(p);
	p->normal = vec3_normalize(p->normal);

}

t_pixel		*pixel_new(double t, t_object *obj, t_mrt_ray *ray)
{
	t_pixel	*tmp;

	tmp = malloc(sizeof(t_pixel));
	tmp->obj = obj;
	tmp->ray = ray;
	tmp->is_cap = 0;
	tmp->light_cof = 1;
	if (ray != NULL)
		tmp->hitpoint = mrt_ray_point(t, ray);
	tmp->t = t;
	return (tmp);
}
