/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:55:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/19 18:05:45 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

extern t_conf *g_conf;

t_conf	*mrt_init(void)
{
	g_conf = (t_conf *)malloc(sizeof(t_conf));
	g_conf->errcode = 0;
}
