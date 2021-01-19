/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:15:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/19 18:02:12 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_conf	g_conf;

int main(int argc, char **argv)
{
	int 	fd;
	char	*line;
	int		r;

	mrt_init();
	mrt_parser(argc, argv);
	return (0);
}