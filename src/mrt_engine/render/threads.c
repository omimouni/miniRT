/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:57:20 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/03 11:12:35 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../bonus.h"

extern	t_conf	*g_conf;

// void	*mrt_render_chunk(void	*vargp)
// {

// }

static t_dimension	mrt_calc_dimenstion(int offset_x, int offset_y)
{
	t_dimension	dim;

	dim.h_even = g_conf->height % 2;
	dim.w_even = g_conf->width % 2;
	dim.height_start = (offset_y * (g_conf->height / 2));
	dim.height_end = ((offset_y + 1) * (g_conf->height / 2));
	dim.width_start = (offset_x * (g_conf->height / 2));
	dim.width_end = ((offset_x + 1) * (g_conf->height / 2));
	return (dim);
}

void		mrt_threads_loop()
{
	pthread_t	thread_id;
	t_dimension	dim;

	dim = mrt_calc_dimenstion(0, 1);
	// mrt_calc_dimenstion(1 ,&width, &height);
	printf("\nThreads Starts\n");
	// printf("%d %d \n", width, height);
	printf("Threads End\n");
}
