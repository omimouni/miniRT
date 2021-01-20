/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:41:18 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/20 11:51:55 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf *g_conf;

void	mrt_window_loop()
{
	g_conf->mlx.ptr = mlx_init();
	g_conf->mlx.win = mlx_new_window(g_conf->mlx.ptr, 200, 200, "miniRT");
	
	mlx_loop(g_conf->mlx.ptr);
}