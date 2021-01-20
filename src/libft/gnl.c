/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:18:24 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/20 11:11:19 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO: add ft functions instead of standards 

static int	gnl_buffer(int fd, char **ptr)
{
	int		n_char;
	char	*buffer;
	char	*tmp;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((n_char = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n_char] = '\0';
		if (*ptr == NULL)
			*ptr = strdup(buffer);
		else
		{
			tmp = ft_strjoin(*ptr, buffer);
			free(*ptr);
			*ptr = tmp;
		}
		if (strchr(*ptr, '\n'))
			break;
	}
	free(buffer);
	return (n_char);
}

static	int	gnl_set_line(char **ptr, int length, char **line)
{
	char	*tmp;

	free(*line);
	if ((*ptr)[length] == '\n')
	{
		*line = ft_substr(*ptr, 0, length);
		tmp = strdup(*ptr + length + 1);
		free(*ptr);
		*ptr = tmp;
	}
	else
	{
		*line = strdup(*ptr);
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (1);
}

int	gnl(int fd, char **line)
{
	static char		*ptr;
	int				n_char;
	int				length;

	if (fd < 0 || line == NULL)
		return (-1);
	n_char = gnl_buffer(fd, &ptr);
	if (n_char < 0)
		return (-1);
	*line = strdup("");
	if (ptr == NULL)
		return (0);
	length = 0;
	while (ptr[length] != '\n' && ptr[length] != '\0')
		length++;
	return (gnl_set_line(&ptr, length, line));
}