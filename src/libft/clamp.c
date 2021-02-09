/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:49:48 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 09:00:15 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_clamp_int(int i, int min, int max)
{
	if (i < min)
		return (min);
	else if (i > max)
		return (max);
	else
		return (i);
}
