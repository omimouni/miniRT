/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:33:11 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 03:14:06 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>

typedef struct	s_vec3f {
	double		x;
	double		y;
	double		z;
}				t_vec3f;

typedef	t_vec3f	t_pt3f;
typedef	t_vec3f	t_rgb;

typedef struct	s_ray3f {
	t_pt3f		*start;
	t_vec3f		*dir;
}				t_ray3f;

t_vec3f			*vec3f_new(double x, double y, double z);
t_vec3f			*vec3f_add(t_vec3f *v, t_vec3f *w);
t_vec3f			*vec3f_scalar(double n, t_vec3f *v);
double			vec3f_length(t_vec3f *v);
t_vec3f			*vec3f_cross(t_vec3f *v, t_vec3f *w);
void			vec3f_free(t_vec3f *v);
t_vec3f			*vec3f_normalize(t_vec3f *v);
t_ray3f			*ray3f_new(t_vec3f *p, t_vec3f *d);
void			ray3f_free(t_ray3f *r);
#endif
