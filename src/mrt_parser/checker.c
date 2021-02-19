/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:58:41 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/19 11:40:27 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	mrt_is_integer(char *s, char type)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			if (type)
				return (1);
			mrt_trigger_error(21);
		}
		i++;
	}
	return (0);
}

void	mrt_is_double(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (flag)
				mrt_trigger_error(23);
			if (!(i != 0 && ft_isdigit(s[i + 1])
				&& ft_isdigit(s[i - 1])))
				mrt_trigger_error(23);
			flag = 1;
		}
		else if (!ft_isdigit(s[i]))
			mrt_trigger_error(23);
		i++;
	}
}