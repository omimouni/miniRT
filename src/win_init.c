/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:23:32 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 04:42:01 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	win_init(t_conf *conf)
{
	conf->mlx = mlx_init();
	conf->win = mlx_new_window(conf->mlx, conf->width, conf->height,
		WINDOW_TITLE);
}
