/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 10:50:16 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

void	parse_resolution(char **key)
{
	double	width;
	double	height;

	width = ft_atoi(key[1]);
	height = ft_atoi(key[2]);

	if (width == 0)
		mrt_trigger_error(3);
	if (height == 0)
		mrt_trigger_error(4);
	printf("%f %f \n", width, height);
}