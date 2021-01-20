/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:25 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/20 11:11:38 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	mrt_split_line(char *line)
{
	char	**keywords;

	keywords = ft_split(line);	
}

void		mrt_parser(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open("scenes/test.rt", O_RDONLY);
	while (gnl(fd, &line))
	{
		mrt_split_line(line);
	}
}