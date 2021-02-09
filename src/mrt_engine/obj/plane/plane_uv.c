/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_uv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:30:56 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 09:37:06 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		mrt_uv_plane_calc(double *up, double *vp, t_pixel *p)
{
	double		u;
	double		v;
	t_vector3	p2;

	p2 = vec3_sub(p->hitpoint, ((t_plane *)p->obj->object)->cords);
	*up = fabs(fmod(p2.x, 1));
	*vp = fabs(fmod(p2.z, 1));
}

void			mrt_uv_plane(t_pixel *p)
{
	double		u;
	double		v;
	char		*dst;

	mrt_uv_plane_calc(&u, &v, p);
	if (fmod(u + v, 2) == 0)
		p->ray->color = color_from_rgb(0, 0, 0);
	else
		p->ray->color = color_from_rgb(255, 255, 255);
}
