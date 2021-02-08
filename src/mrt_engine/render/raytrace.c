/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:43:13 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 20:24:01 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;
extern t_mlx_img	f;
extern int	g_img_height;
extern int	g_img_width;

static void		mrt_uv_sphere_calc(double *up, double *vp, t_pixel *p)
{
	double		u;
	double		v;
	t_vector3	p2;

	p2 = vec3_sub(p->hitpoint, ((t_sphere *)p->obj->object)->center);

	u = atan2(p2.x, p2.z) / (2 * M_PI);
	u = 1 - (u + 0.5);
	v = 1 - (acos(p2.y / (((t_sphere *)p->obj->object)->diameter / 2)) / M_PI);	
	*up = floor(u * g_img_width);
	*vp = floor(v * g_img_height);
	// printf("%d %d \n", g_img_width, g_img_height);
}

static void		mrt_uv_sphere(t_pixel *p)
{
	double		u;
	double		v;
	char		*dst;

	mrt_uv_sphere_calc(&u, &v, p);
	dst = f.addr + ((int)v * f.line_height + (int)u * (f.bpp / 8));
	p->obj->color = color_from_hex(*(int *)dst);
}

static void		mrt_uv_plane_calc(double *up, double *vp, t_pixel *p)
{
	double		u;
	double		v;
	t_vector3	p2;

	// p2 = p->hitpoint;
	p2 = vec3_sub(p->hitpoint, ((t_plane *)p->obj->object)->cords);
	*up = fabs(fmod(p2.x, 1));
	*vp = fabs(fmod(p2.z, 1));
	// printf("%f %f \n", *up, *vp);
}


static void		mrt_uv_plane(t_pixel *p)
{
	double		u;
	double		v;
	char		*dst;

	mrt_uv_plane_calc(&u, &v, p);
	u = floor(u * (g_img_height / 5));
	v = floor(v * (g_img_width / 5));
	dst = f.addr + ((int)u * f.line_height + (int)v * (f.bpp / 8));
	p->obj->color = color_from_hex(*(int *)dst);
}

static	void	mrt_calc_light(t_pixel *pixel)
{
	if (pixel->obj != NULL)
	{
		pixel->ray->color = pixel->obj->color;
		if (g_conf->is_bonus)
		{
			pixel->obj->type == MRT_TYPE_SPHERE ? mrt_uv_sphere(pixel) : NULL;
			pixel->obj->type == MRT_TYPE_PLANE ? mrt_uv_plane(pixel) : NULL;
		}
		mrt_light_points(pixel);
		mrt_light_ambiant(pixel);
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
