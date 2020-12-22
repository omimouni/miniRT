/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 04:15:43 by omimouni          #+#    #+#             */
/*   Updated: 2020/12/22 04:25:25 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s) + 1;
	ptr = malloc(sizeof(char) * i);
	ptr[--i] = '\0';
	while (i + 1)
	{
		ptr[i] = s[i];
		i--;
	}
	return (ptr);
}

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


int	ft_read_buffer(int fd, char **ptr)
{
	char	*buffer;
	char	*tmp;
	int		n;

	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if (*ptr == NULL)
			*ptr = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(*ptr, buffer);
			free(*ptr);
			*ptr = tmp;
		}
		if (ft_strchr(*ptr, '\n'))
			break ;
	}
	free(buffer);
	return (n);
}

int	ft_set_line(char **ptr, int len, char **line)
{
	char	*tmp;

	if ((*ptr)[len] == '\n')
	{
		free(*line);
		*line = ft_substr(*ptr, 0, len);
		tmp = ft_strdup(*ptr + len + 1);
		free(*ptr);
		*ptr = tmp;
	}
	else
	{
		free(*line);
		*line = ft_strdup(*ptr);
		free(*ptr);
		*ptr = NULL;
		return (0);
	}
	return (1);
}

int	gnl(int fd, char **line)
{
	static char	*ptr[1024];
	int			n;
	int			len;

	if (fd < 0 || line == NULL)
		return (-1);
	n = ft_read_buffer(fd, &ptr[fd]);
	if (n < 0)
		return (-1);
	*line = ft_strdup("");
	if (n == 0 && (ptr[fd] == NULL))
		return (0);
	len = 0;
	while (ptr[fd][len] != '\n' && ptr[fd][len] != '\0')
		len++;
	return (ft_set_line(&ptr[fd], len, line));
}