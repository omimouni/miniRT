/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:24:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/02 21:19:06 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H
# include <math.h>
# include <stdio.h>

typedef struct		s_vector3 {
	double			x;
	double			y;
	double			z;
}					t_vector3;
typedef	t_vector3	t_point3;

t_vector3			vec3_new(double x, double y, double z);
t_vector3			vec3_add(t_vector3 v, t_vector3 w);
double				vec3_length(t_vector3 v);
t_vector3			vec3_normalize(t_vector3 v);
t_vector3			vec3_sub(t_vector3 v, t_vector3 w);
t_vector3			vec3_mult(double n, t_vector3 v);
t_vector3			vec3_cross(t_vector3 v, t_vector3 w);
double				vec3_dot(t_vector3 v, t_vector3 w);
void				vec3_show(t_vector3	v);
#endif
