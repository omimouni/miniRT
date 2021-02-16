/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/16 14:30:14 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern t_conf	*g_conf;

void	mrt_render(void)
{
	printf("🖥  Rendering Scene\n");
	printf("👾 \033[0;32mProgress ...");
	mrt_render_loop(0, g_conf->width, 0, g_conf->height);
	printf("\033[0m ✅\n");
	printf("\n🤵 waiting for the next command\n");
}
