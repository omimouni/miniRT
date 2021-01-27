/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:55:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/27 22:01:59 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf	*g_conf;

void	mrt_init(void)
{
	g_conf = (t_conf *)malloc(sizeof(t_conf));
	g_conf->errcode = 0;
	g_conf->is_save = 0;
	g_conf->height = 423;
	g_conf->width = 752;
	
}
