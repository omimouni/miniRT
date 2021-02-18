/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:25 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/18 10:07:59 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void		mrt_trigger_error(int code)
{
	g_conf->errcode = code;
	mrt_error();
}

void		free_split(char **key)
{
	int	i;

	i = 0;
	while (key[i] != NULL)
	{
		free(key[i]);
		i++;
	}
	free(key[i]);
	free(key);
}

int				mrt_parser_switch(char *line)
{
	char	**key;
	int		i;

	// Replace \t by spaces
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	key = ft_split(line, ' ');
	if (key[0] == NULL)
	{
		free_split(key);
		return (0);
	}
	if (!ft_strncmp(key[0], "R", 1))
		mrt_parse_resolution(key);
	else if (!ft_strncmp(key[0], "A", 1))
		mrt_parse_ambient(key);
	else if (!ft_strncmp(key[0], "cy", 2))
		mrt_parse_cylinder(key);
	else if (!ft_strncmp(key[0], "c", 2))
		mrt_parse_camera(key);
	else if (!ft_strncmp(key[0], "pl", 2))
		mrt_parse_plane(key);
	else if (!ft_strncmp(key[0], "sp", 2))
		mrt_parse_sphere(key);
	else if (!ft_strncmp(key[0], "l", 1))
		mrt_parse_light(key);
	else if (!ft_strncmp(key[0], "tr", 2))
		mrt_parse_triangle(key);
	else if (!ft_strncmp(key[0], "sq", 2))
		mrt_parse_square(key);
	free_split(key);
	return (0);
}

void			mrt_parser(int argc, char **argv)
{
	int		fd;
	char	*line;

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
		mrt_parser_switch(line);
		free(line);
	}
	free(line);
}
