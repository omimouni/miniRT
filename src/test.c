/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:15:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/29 22:23:11 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_conf	*g_conf;

int main(int argc, char **argv)
{
	int 	fd;
	char	*line;

	mrt_init();
	mrt_parser(argc, argv);
	if (g_conf->is_save)
		mrt_save_image();
	else
		mrt_window_loop();
	return (0);
}