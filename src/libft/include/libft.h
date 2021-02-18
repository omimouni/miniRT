/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:24:19 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/18 10:46:28 by omimouni         ###   ########.fr       */
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

# include "ft_string.h"
# include "ft_maths.h"
# include "linked_list.h"

int		gnl(int fd, char **line);

double	ft_parsefloat(char *s);
long	ft_clamp_int(long i, long min, long max);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
#endif
