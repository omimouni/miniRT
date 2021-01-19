/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:25 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/19 18:04:27 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
extern t_conf *g_conf;

void	mrt_error(int code)
{
	
}
void	mrt_parser(int argc, char **argv)
{
	int	fd;

	fd = open("scenes/test.rt", O_RDONLY);
	if (fd < 0)
}