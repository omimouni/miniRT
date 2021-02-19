/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 10:39:40 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 12:25:30 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

/*
 ** DOCS:	https://harm-smits.github.io/42docs/libs/minilibx/events.html
 ** @todo:	Learn about hooks
*/

int	mrt_quit_btn(void)
{
	mrt_quit();
	return (0);
}

void	mrt_hooks(void)
{
	mlx_hook(g_conf->mlx.win, 17, 0, mrt_quit_btn, NULL);
	mlx_key_hook(g_conf->mlx.win, mrt_key_handler, NULL);
}
