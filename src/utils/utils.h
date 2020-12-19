/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:04:27 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/19 04:16:17 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_vec3f {
	double		x;
	double		y;
	double		z;
}				t_vec3f;

t_vec3f	*vec3f_new(double x, double y, double z);

#endif