/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 17:24:57 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;
extern t_mlx_img	f;

static void		mrt_uv_sphere(t_pixel *p)
{
	double		u;
	double		v;
	double		u2;
	double		v2;
	double		theta;
	t_vector3	p2;
	t_vector3	vec;
	double		phi;
	t_color		color;
	char		*dst;

	p2 = vec3_sub(p->hitpoint, ((t_sphere *)p->obj->object)->center);
	theta = atan2(p2.x, p2.z);
	phi = acos(p2.y / (((t_sphere *)p->obj->object)->diameter / 2));
	u = theta / (2 * M_PI);
	u = 1 - (u + 0.5);
	v = 1 - (phi / M_PI);
	u2 = floor(u * 640);
	v2 = floor(v * 400);

	dst = f.addr + ((int)v2 * f.line_height + (int)u2 * (f.bpp / 8));
	p->obj->color = color_from_hex(*(int *)dst);
}

static	void	mrt_calc_light(t_pixel *pixel)
{
	if (pixel->obj != NULL)
	{
		pixel->ray->color = pixel->obj->color;
		pixel->obj->type == MRT_TYPE_SPHERE ? mrt_uv_sphere(pixel) : NULL;
		mrt_light_points(pixel);
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
		if (obj->type == MRT_TYPE_TRIANGLE)
			tmp_t = mrt_triangle_intersection(ray, obj);
		if (tmp_t < pixel->t && tmp_t > 0){
			mrt_pixel_update(pixel, tmp_t, ray, obj);
		}
		current = current->next;
	}

	mrt_calc_light(pixel);
	free(pixel);
}
