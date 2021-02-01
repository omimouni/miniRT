/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 14:47:55 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

static double	mrt_intersect_sphere_equation(t_mrt_ray *ray, t_sphere *s,
	double *t1, double *t2)
{
	double		k1;
	double		k2;
	double		k3;
	double		det;

	k1 = vec3_dot(ray->direction, ray->direction);
	k2 = 2 * vec3_dot(vec3_sub(ray->origin, s->center), ray->direction);
	k3 = vec3_dot(vec3_sub(ray->origin, s->center),
		vec3_sub(ray->origin, s->center)) - s->diameter * s->diameter;
	det = k2 * k2 - 4 * k1 * k3;
	if (det < 0)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
	}
	else
	{
		*t1 = (-k2 + sqrt(det)) / (2 * k1);
		*t2 = (-k2 - sqrt(det)) / (2 * k1);
	}
	return (det);
}

static double	mrt_intersect_sphere(t_mrt_ray *ray, t_object *obj)
{
	double		t1;
	double		t2;

	if (mrt_intersect_sphere_equation(ray, obj->object, &t1, &t2) < 0)
		return (INFINITY);
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

static void		mrt_pixel_update(t_pixel *p, double t, t_mrt_ray *ray,
				t_object *obj)
{
	p->t = t;
	p->hitpoint = mrt_ray_point(t, ray);
	p->obj = obj;
}

void			mrt_raytrace(t_mrt_ray *ray)
{
	t_generic_list	*current;
	t_object		*obj;
	t_pixel			*pixel;
	double			tmp;

	current = g_conf->objs;
	pixel = pixel_new(INFINITY, NULL, NULL);
	while (current != NULL)
	{
		obj = (t_object *)current->obj;
		if (obj->type == MRT_TYPE_SPHERE)
		{
			tmp = mrt_intersect_sphere(ray, obj);
			if (tmp < pixel->t)
				mrt_pixel_update(pixel, tmp, ray, obj);
		}
		current = current->next;
	}
	if (pixel->obj != NULL)
		ray->color = color_rgba_struct(pixel->obj->color);
	else
		ray->color = 0x00000;
	free(pixel);
}
