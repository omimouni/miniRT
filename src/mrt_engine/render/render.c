/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/03 10:04:03 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../bonus.h"

extern t_conf	*g_conf;

void	mrt_render(void)
{
	printf("🖥  Rendering Scene\n");
	printf("👾 \033[0;32mProgress ...");
	if (g_conf->is_bonus)
		mrt_threads_loop();
	else
		mrt_render_loop(g_conf->width, g_conf->height);
	printf("\033[0m ✅\n");
	printf("\n🤵 waiting for the next command\n");
}
