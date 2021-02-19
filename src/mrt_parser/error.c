/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:20:40 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 12:50:06 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

char	*g_err_list[] = {
	"The first argument must be a file", // 1
	"The scene file isn't valid", // 2
	"The second argument can only be --save", // 3
	"Width can't be null or zero", //  4
	"Height can't be null or zero", //  5
	"Width and height must be Integers", //  6
	"Ambient light intensity should be in range [0.0, 1.0]", //  7
	"The given color format isn't valid", //  8
	"A color value can only be an Integer", //  9
	"No camera found", //  10
	"The cordinates are invalid", //  11
	"The vector is not normalized", //  12
	"Camera is invalid", //  13
	"No light found in the scene.", //  14
	"Invalid format", // 15
	"Height and width can't be negative", // 16
	"input can only be a number", //17
	"Resolution can only be set once", //18
	"Ambient light can only be set once", //19
	"The parsed file must have R and A.", //20
	"Value can only be an integer.", //21
	"Wrong format .rt file", //22
	"Float format is invalid.", //23
	"FOV should be in range [0, 180]", //24
	"Light intensity should be in range [0.0, 1.0]", //25
	"sphere diametre can't be null or negative", //26
	"cylinder dimensions can't be null or negative", //27
};

void	mrt_error(void)
{
	printf("\033[0;31mError\n");
	printf("\n (⚠️ %dERR) %s\033[0m\n", g_conf->errcode,
		*(g_err_list + g_conf->errcode - 1));
	exit(-1);
}
