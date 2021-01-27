/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:24:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/27 16:16:13 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_MATHS_H
# define FT_MATHS_H

typedef struct		s_vector3 {
	double			x;
	double			y;
	double			z;
}					t_vector3;

typedef	t_vector3	t_point3;

t_vector3			vec3_new(double x, double y, double z);
t_vector3			vec3_add(t_vector3 v, t_vector3 w);
#endif
