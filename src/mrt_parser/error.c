/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:20:40 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 10:50:39 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

char	*g_err_list[] = {
	"The first argument must be a file.",
	"The scene file isn't valid.",
	"The second argument can only be --save.",
	
	"Resoluion width can't be null or zero.", // Index 3
	"Resoluion height can't be null or zero.", // Index 4
};

void	mrt_error(void)
{
	printf("Error\n");
	printf("ERROR CODE %d: %s\n", g_conf->errcode,
		*(g_err_list + g_conf->errcode - 1));
	exit(-1);
}
