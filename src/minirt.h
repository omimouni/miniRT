/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:13:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/24 17:38:42 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WINDOW_TITLE "miniRT"
# include "libft/libft.h"
# include "types.h"
# include <mlx.h>

void	mrt_init();
void	mrt_parser(int argc, char **argv);

void	mrt_mlx_init(void);
void	mrt_render(void);
void	mrt_window_loop(void);
void	mrt_save_image(void);

void	mrt_put_pixel(size_t x, size_t y, int color);

t_mrt_ray	*mrt_ray_init(t_point3 orig, t_vector3 dir);
void		mrt_ray_free(t_mrt_ray *ray);
#endif