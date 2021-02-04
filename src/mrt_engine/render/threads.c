/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:57:20 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/04 18:25:13 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../bonus.h"
#include <sys/types.h>

pthread_mutex_t	g_running_mutex = PTHREAD_MUTEX_INITIALIZER;
volatile int	g_running_threads;

extern	t_conf	*g_conf;

void	*mrt_render_chunk(void	*vargp)
{
	t_dimension	*dim;

	dim = (t_dimension *)vargp;

	// printf("%d %d %d : h %d %d w %d %d\n", gettid(),dim->offset_x, dim->offset_y, dim->height_start, dim->height_end, dim->width_start, dim->width_end);
	// mrt_render_loop(dim->width_start, dim->width_end,
	// 	dim->height_start, dim->height_start);
	pthread_mutex_lock(&g_running_mutex);
	g_running_threads--;
	pthread_mutex_unlock(&g_running_mutex);
}

static t_dimension	mrt_calc_dimenstion(int offset_x, int offset_y)
{
	t_dimension	dim;

	dim.h_even = g_conf->height % 2;
	dim.w_even = g_conf->width % 2;
	dim.height_start = offset_y * (g_conf->height / 3);
	dim.height_end = g_conf->height / (3 - offset_y);
	dim.width_start = offset_x * (g_conf->width / 3);
	dim.width_end = g_conf->width / (4 - offset_x);
	dim.offset_x = offset_x;
	dim.offset_y = offset_y;
	return (dim);
}

void		mrt_threads_loop()
{
	pthread_t	thread_id[4];
	t_dimension	dim;

	g_running_threads = 0;
	// mrt_calc_dimenstion(1 ,&width, &height);
	// printf("\nThreads Starts\n");
	
	pthread_mutex_lock(&g_running_mutex);
	g_running_threads++;
	dim = mrt_calc_dimenstion(0, 0);
	dim.id = &thread_id[0];
	pthread_create(&thread_id[0], NULL, mrt_render_chunk ,&dim);
	pthread_mutex_unlock(&g_running_mutex);

	// pthread_mutex_lock(&g_running_mutex);
	// g_running_threads++;
	// dim = mrt_calc_dimenstion(0, 1);
	// dim.id = &thread_id[1];
	// pthread_create(&thread_id[1], NULL, mrt_render_chunk ,&dim);
	// pthread_mutex_unlock(&g_running_mutex);


	// pthread_mutex_lock(&g_running_mutex);
	// g_running_threads++;
	// pthread_mutex_unlock(&g_running_mutex);

	// dim = mrt_calc_dimenstion(1, 0);
	// dim.id = &thread_id[2];
	// pthread_create(&thread_id[2], NULL, mrt_render_chunk ,&dim);
	
	// pthread_mutex_lock(&g_running_mutex);
	// g_running_threads++;
	// pthread_mutex_unlock(&g_running_mutex);

	// dim = mrt_calc_dimenstion(1, 1);
	// dim.id = &thread_id[3];
	// pthread_create(&thread_id[3], NULL, mrt_render_chunk ,&dim);


	while (g_running_threads > 0)
		sleep(1);
	printf("I'm Done");
	// printf("Threads End\n");
}
