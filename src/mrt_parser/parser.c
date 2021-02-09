/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:25 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 10:46:44 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void		mrt_trigger_error(int code)
{
	g_conf->errcode = code;
	mrt_error();
}

void			mrt_parser_switch(char *line)
{
	char	**key;

	key = ft_split(line, ' ');
	!ft_strncmp(key[0], "R", 1) ? parse_resolution(key) : NULL;
}

void			mrt_parser(int argc, char **argv)
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
		mrt_parser_switch(line);
	free(line);
}
