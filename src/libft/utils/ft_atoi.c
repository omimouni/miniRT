/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:34:51 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 10:48:41 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int n)
{
	if ((unsigned long)n > __LONG_MAX__)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		n;
	char	*s;
	int		flag;

	flag = 1;
	if (str == NULL)
		return (0);
	s = (char *)str;
	while (*s == ' ' || *s == '\n' || *s == '\r' || *s == '\t'
			|| *s == '\v' || *s == '\f')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag = -1;
		s++;
	}
	n = 0;
	while (*s >= '0' && *s <= '9' && *s != '\0')
	{
		if (check(n))
			return ((flag > 0 ? -1 : 0));
		n = (n * 10) + (*s - '0');
		s++;
	}
	return (n * flag);
}