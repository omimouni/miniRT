/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:13:04 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/24 18:06:45 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	l;

	l = 0;
	if (start > ft_strlen(s))
	{
		if (!(ptr = (char *)malloc(1)))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	while (l < len && s[l + start] != '\0')
		l++;
	if (!(ptr = (char *)malloc(sizeof(char) * l + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}