/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:50:42 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 11:58:02 by omimouni         ###   ########.fr       */
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
	if (s_float == NULL)
		return (n);
	n_float = ft_atoi(s_float + 1);
	return (n + n_float / (10 * ft_strlen(s_float + 1)));
}
