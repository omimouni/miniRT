/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:26:47 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 12:27:23 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s1) + 1;
	if (!(ptr = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	ptr[--i] = '\0';
	while (i + 1)
	{
		ptr[i] = s1[i];
		i--;
	}
	return (ptr);
}
