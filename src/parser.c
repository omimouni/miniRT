/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 01:58:31 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 06:00:36 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser(int argc, char **argv, t_conf *conf)
{
	int	fd;

	conf->width = 800;
	conf->height = 450;
	fd = open(argv[1], O_RDONLY);
	printf("%d", fd);
}
