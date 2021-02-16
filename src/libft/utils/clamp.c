/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:49:48 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/16 09:27:12 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_clamp_int(long i, long min, long max)
{
	if (i < min)
		return (min);
	else if (i > max)
		return (max);
	else
		return (i);
}
