/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:16:58 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/20 15:18:33 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}

static void		ft_bzero(void *s, size_t n)
{
	if (n > 0)
		s = ft_memset(s, 0, n);
}

void			*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(ptr = (void *)malloc(size * count)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
