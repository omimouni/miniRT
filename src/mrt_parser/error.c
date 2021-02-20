/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:20:40 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 16:40:46 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

char	*g_err_list[] = {
	"The first argument must be a file",
	"The scene file isn't valid",
	"The second argument can only be --save",
	"Width can't be null or zero",
	"Height can't be null or zero",
	"Width and height must be Integers",
	"Ambient light intensity should be in range [0.0, 1.0]",
	"The given color format isn't valid",
	"A color value can only be an Integer",
	"No camera found",
	"The cordinates are invalid",
	"The vector is not normalized",
	"Camera is invalid",
	"No light found in the scene.",
	"Invalid format",
	"Height and width can't be negative",
	"input can only be a number",
	"Resolution can only be set once",
	"Ambient light can only be set once",
	"The parsed file must have R and A.",
	"Value can only be an integer.",
	"Wrong format .rt file",
	"Float format is invalid.",
	"FOV should be in range [0, 180]",
	"Light intensity should be in range [0.0, 1.0]",
	"sphere diametre can't be null or negative",
	"cylinder dimensions can't be null or negative",
	"square size can't be null or negative",
	"file isn't an .rt file",
};

void	mrt_error(void)
{
	printf("\033[0;31mError\n");
	printf("\n (⚠️ %dERR) %s\033[0m\n", g_conf->errcode,
		*(g_err_list + g_conf->errcode - 1));
	exit(-1);
}
