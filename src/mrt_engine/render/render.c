/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/31 11:55:03 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

static t_vector3	mrt_ray_calc_dir(size_t x, size_t y)
{
	t_vector3	tmp;
	t_vector3	u;
	t_vector3	r;

	r = vec3_mult(g_conf->current_camera->scene_w * camera_position_y(x),
		g_conf->current_camera->right);
	u = vec3_mult(g_conf->current_camera->scene_h * camera_position_y(y),
		g_conf->current_camera->up);
	tmp = vec3_add(g_conf->current_camera->normal, u);
	tmp = vec3_add(tmp, r);
	return (vec3_normalize(tmp));
}

static	double		solve_sphere(t_sphere *s, t_mrt_ray *ray)
{
	double	k1;
	double	k2;
	double	k3;
	double	t1;
	double	t2;
	double	d;

	k1 = vec3_dot(ray->direction, ray->direction);
	k2 = 2 * vec3_dot(vec3_sub(s->center, ray->origin),
				ray->direction);
	k3 = vec3_dot(vec3_sub(s->center, ray->origin),
		vec3_sub(s->center, ray->origin)) - s->diameter * s->diameter;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
		return (0);
	else
	{
		t1 = (-k2 + sqrt(d)) / 2 * k1;
		t2 = (-k2 - sqrt(d)) / 2 * k1;
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
}

static	t_object	*mrt_raytrace(t_mrt_ray *ray)
{
	t_generic_list	*current;
	t_object		*obj;
	double			t;
	double			tmp;

	t = UINT32_MAX;
	current = g_conf->objs;
	while (current != NULL)
	{
		if (((t_object *)current->obj)->type == MRT_TYPE_SPHERE)
		{
			//@todo: Solve sphere equation
			tmp = solve_sphere(((t_object *)current->obj)->object, ray);
			if (tmp < t)
			{
				t = tmp;
				obj = current->obj;
				printf("IM HERE\n");
			}
		}
		current = current->next;
	}
	return (obj);
}

static void 		mrt_render_loop()
{
	size_t		i;
	size_t		j;
	t_mrt_ray	*ray;
	t_object	*obj;

	i = 0;
	ray = mrt_ray_init(g_conf->current_camera->origin);
	while (i < g_conf->width)
	{
		j = 0;

		while (j < g_conf->height)
		{
			mrt_ray_update_dir(&ray, mrt_ray_calc_dir(i, j));
			obj = mrt_raytrace(ray);		
			if (g_conf->is_save)
				// @todo: add bmp renderer
				continue;
			else
			{
				mrt_put_pixel(i, j, color_rgba_struct(obj->color));
				if (color_rgba_struct(obj->color))
					printf("%x\n", color_rgba_struct(obj->color));
			}
			j++;
		}
		i++;
	}
}

void				mrt_render()
{
	printf("< 🖥  Rendering Scene >\n");
	printf("-> 👾 \033[0;32mProgress ...");
	mrt_render_loop();
	printf("\033[0m ✅\n");
	printf("< 🤵 waiting for the next command >\n");
}
