/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:49:01 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/04 18:08:06 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BONUS_H
# define BONUS_H
# include <pthread.h>

typedef struct	s_dimension {
	int			width_start;
	int			width_end;
	int			height_start;
	int			height_end;
	int			offset_x;
	int			offset_y;
	int			w_even;
	int			h_even;
	pthread_t	*id;
}				t_dimension;

void		mrt_threads_loop();
# endif