/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 03:37:43 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/20 02:41:48 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_conf	*conf;

	conf = malloc(sizeof(t_conf));
	parser(argc, argv, conf);
	win_init(conf);
	win_hook(conf);
	render(conf);
	mlx_loop(conf->mlx);
	return (0);
}
