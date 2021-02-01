/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:24:19 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 15:52:31 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 255
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# include "string/ft_string.h"
# include "ft_maths/ft_maths.h"
# include "linked_list/linked_list.h"
# include "bmp/ft_bmp.h"

int		gnl(int fd, char **line);

double	ft_parsefloat(char *s);
int		ft_clamp_int(int i, int min, int max);
#endif
