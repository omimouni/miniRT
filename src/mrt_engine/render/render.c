/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:00:07 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/31 16:13:28 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

extern t_conf	*g_conf;

// @todo: Implement Multithreads 

void				mrt_render()
{
	printf("< 🖥  Rendering Scene >\n");
	printf("-> 👾 \033[0;32mProgress ...");
	mrt_render_loop();
	printf("\033[0m ✅\n");
	printf("< 🤵 waiting for the next command >\n");
}
