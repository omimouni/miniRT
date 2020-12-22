/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 03:37:43 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 05:59:57 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main_prod(int argc, char **argv)
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

int	main_test(int argc, char **argv)
{
	t_conf	*conf;

	conf = malloc(sizeof(t_conf));
	parser(argc, argv, conf);
	render(conf);
	return (0);
}

int	main(int argc, char **argv)
{
	return (main_test(argc, argv));
}