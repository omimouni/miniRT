/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 10:39:40 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 18:34:35 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

/*
 ** DOCS:	https://harm-smits.github.io/42docs/libs/minilibx/events.html
 ** @todo:	Learn about hooks
*/

void	mrt_hooks(void)
{
	mlx_key_hook(g_conf->mlx.win, mrt_key_handler, NULL);
}
