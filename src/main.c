/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:15:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/16 18:27:14 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_conf		*g_conf;

int	main(int argc, char **argv)
{
	mrt_init();
	mrt_parser(argc, argv);
	g_conf->is_bonus = 1;
	if(g_conf->cameras == NULL)
		mrt_trigger_error(10);
	if (g_conf->is_save)
		mrt_save_image();
	else
		mrt_window_loop();
	return (0);
}
