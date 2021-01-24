/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:37:29 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/24 16:50:23 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONF_H
# define CONF_H
# include <stdbool.h>

typedef	struct	s_mlx_img {
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_height;
	int			endian;
}				t_mlx_img;

typedef	struct	s_mlx {
	void		*ptr;
	void		*win;
	t_mlx_img	img;
}				t_mlx;

typedef	struct	s_conf {
	unsigned int	errcode;
	unsigned int	height;
	unsigned int	width;
	unsigned char	is_save;
	t_mlx			mlx;
} 				t_conf;

#endif 