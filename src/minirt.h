/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:13:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/19 18:02:58 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"

typedef	struct	s_conf {
	int			errcode;
} 				t_conf;


t_conf	*mrt_init();
void	mrt_parser(int argc, char **argv);
void	mrt_error(int code);
#endif