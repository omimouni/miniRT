/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:13:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/29 23:35:32 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WINDOW_TITLE "miniRT"

# define MRT_RENDER_WINDOW 10
# define MRT_RENDER_IMAGE 11

# define MRT_TYPE_CAMERA 20

# define MRT_KEY_ESC 256

# include "libft/libft.h"
# include "types.h"
# include <mlx.h>

void			mrt_init();
void			mrt_parser(int argc, char **argv);
void			mrt_error(void);

void			mrt_render();
void			mrt_window_loop(void);
void			mrt_save_image(void);
void			mrt_put_pixel(size_t x, size_t y, int color);

t_mrt_ray		*mrt_ray_init(t_point3 orig, t_vector3 dir);
void			mrt_ray_free(t_mrt_ray *ray);

int				mrt_key_handler(int keycode);
void			mrt_update_window(void);

t_camera		*camera_new(t_point3 origin, t_vector3 normal, int fov);

int				color_rgba(int r, int g, int b, int a);
t_color			color_new(int hex);

#endif
