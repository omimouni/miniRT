/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:52:28 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/27 16:20:06 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	p;
	size_t	q;
	size_t	i;
	char	*tmp;

	p = ft_strlen(s1);
	q = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (p + q + 1))))
		return (NULL);
	i = 0;
	tmp = (char *)s1;
	while (*tmp)
		ptr[i++] = *tmp++;
	tmp = (char *)s2;
	while (*tmp)
		ptr[i++] = *tmp++;
	ptr[i] = '\0';
	return (ptr);
}
