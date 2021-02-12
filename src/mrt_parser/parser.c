/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:25 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/12 09:39:46 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void		mrt_trigger_error(int code)
{
	g_conf->errcode = code;
	mrt_error();
}

/*
** FIXME: line 35 may segfault at some point.
*/

int				mrt_parser_switch(char *line)
{
	char	**key;

	key = ft_split(line, ' ');
	if (ISN(key[0]))
		return (0);
	if (!ft_strncmp(key[0], "R", 1))
		mrt_parse_resolution(key);
	if (!ft_strncmp(key[0], "A", 1))
		mrt_parse_ambient(key);
	if (!ft_strncmp(key[0], "cy", 2))
		mrt_parse_cylinder(key);
	if (!ft_strncmp(key[0], "c", 2))
		mrt_parse_camera(key);
	if (!ft_strncmp(key[0], "pl", 2))
		mrt_parse_plane(key);
	if (!ft_strncmp(key[0], "sp", 2))
		mrt_parse_sphere(key);
	if (!ft_strncmp(key[0], "l", 1))
		mrt_parse_light(key);
	if (!ft_strncmp(key[0], "tr", 2))
		mrt_parse_triangle(key);
	if (!ft_strncmp(key[0], "sq", 2))
		mrt_parse_square(key);
	return (0);
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
