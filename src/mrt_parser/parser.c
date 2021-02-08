/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:25 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 21:24:25 by omimouni         ###   ########.fr       */
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
	char	**key;

	if (argc < 2 || argc > 3)
		mrt_trigger_error(1);
	if ((fd = open(argv[1], O_RDONLY)) <= -1)
		mrt_trigger_error(2);
	if (argc == 3)
	{
		if (strcmp(argv[2], "--save"))
			mrt_trigger_error(3);
		else
			g_conf->is_save = 1;
	}
	while (gnl(fd, &line) && !g_conf->errcode)
	{
		key = ft_split(line, ' ');
		// if (strncmp(key[0], "R", 2))
		// {
		// 	printf("%s", key[0]);
		// }
		if (!strncmp(key[0], "R", 1))
		{
			g_conf->width = atoi(key[1]);
			g_conf->height = atoi(key[2]);
		}
	}
	// printf("%ld %ld", g_conf->width, g_conf->height);
	free(line);
}