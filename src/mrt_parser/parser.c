/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:25 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 09:52:24 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

static void	mrt_trigger_error(int code)
{
	g_conf->errcode = code;
	mrt_error();
}

void	mrt_parser(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2 || argc > 3)
		mrt_trigger_error(1);
	if ((fd = open(argv[1], O_RDONLY)) <= -1)
		mrt_trigger_error(2);
	if (argc == 3)
	{
		if (strcmp(argv[2], "--save") != 0)
			mrt_trigger_error(3);
		else
			g_conf->is_save = 1;
	}
	while (gnl(fd, &line) && !g_conf->errcode)
	{

	}
	if (g_conf->errcode)
		mrt_trigger_error(g_conf->errcode);
}