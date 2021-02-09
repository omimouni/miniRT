/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:50:42 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 11:31:19 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_parsefloat(char *s)
{
	double	n;
	double	n_float;
	char	*s_float;

	n = ft_atoi(s);
	s_float = ft_strchr(s, '.');
	n_float = s_float == NULL ? ft_atoi(s_float + 1) : 0;
	return (n + n_float / (double)(10 * (s_float 
		!= NULL ? ft_strlen(s_float + 1) : .1)));	
}
