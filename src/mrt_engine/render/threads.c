/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:57:20 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/04 22:57:24 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../bonus.h"
#include <sys/types.h>

pthread_mutex_t	g_running_mutex = PTHREAD_MUTEX_INITIALIZER;
volatile int	g_running_threads;

extern	t_conf	*g_conf;


static t_dimension	mrt_calc_dimenstion(int offset_x, int offset_y)
{
	t_dimension	dim;

	pthread_mutex_lock(&g_running_mutex);

	dim.h_even = g_conf->height % 2;
	dim.w_even = g_conf->width % 2;
	dim.height_start = offset_y * (g_conf->height / 3);
	dim.height_end = g_conf->height / (3 - offset_y);
	dim.width_start = offset_x * (g_conf->width / 3);
	dim.width_end = g_conf->width / (4 - offset_x);
	dim.offset_x = offset_x;
	dim.offset_y = offset_y;
	pthread_mutex_unlock(&g_running_mutex);

	return (dim);
}


void	*mrt_render_chunk(void	*vargp)
{
	t_dimension	dim;
	static int i = 0;


	if (i == 0)
		dim = mrt_calc_dimenstion(0, 0);
	else if (i == 0)
		dim = mrt_calc_dimenstion(0, 1);

	pthread_mutex_lock(&g_running_mutex);

	printf("\n%d %d %d : h %d %d w %d %d\n", i ,dim.offset_x, dim.offset_y, dim.height_start, dim.height_end, 
		dim.width_start, dim.width_end);
	
	mrt_render_loop(dim.width_start, dim.width_end,
		dim.height_start, dim.w_even);
	i++;
	g_running_threads--;
	pthread_mutex_unlock(&g_running_mutex);
}

void		mrt_threads_loop()
{
	pthread_t	thread_id[4];
	t_dimension	dim;

	g_running_threads = 0;

	pthread_mutex_lock(&g_running_mutex);
	g_running_threads++;
	pthread_mutex_unlock(&g_running_mutex);
	dim = mrt_calc_dimenstion(0, 0);
	dim.id = &thread_id[0];
	pthread_create(&thread_id[0], NULL, mrt_render_chunk ,&dim);


	pthread_mutex_lock(&g_running_mutex);
	g_running_threads++;
	pthread_mutex_unlock(&g_running_mutex);
	dim = mrt_calc_dimenstion(0, 1);
	dim.id = &thread_id[1];
	pthread_create(&thread_id[1], NULL, mrt_render_chunk ,&dim);


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
