/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:13:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 14:30:20 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WINDOW_TITLE "miniRT"

# define MRT_RENDER_WINDOW	10
# define MRT_RENDER_IMAGE	11

# ifdef __MACH__
#  define MRT_KEY_ESC 53
#	define MRT_KEY_NUM5	87

#endif

# ifdef __linux__
# 	define MRT_KEY_ESC	65307
#	define MRT_KEY_NUM5	65437
#endif

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# include "types.h"

void			mrt_init();
void			mrt_parser(int argc, char **argv);
void			mrt_error(void);
void			mrt_hooks();

void			mrt_render();
void 			mrt_render_loop();

void			mrt_window_loop(void);
void			mrt_save_image(void);
void			mrt_put_pixel(size_t x, size_t y, int color);

t_mrt_ray		*mrt_ray_init(t_point3 orig);
t_point3		mrt_ray_point(double t, t_mrt_ray *ray);
void			mrt_ray_free(t_mrt_ray *ray);
void			mrt_raytrace(t_mrt_ray	*ray);

int				mrt_key_handler(int keycode);
void			mrt_update_window(void);

t_camera		*camera_new(t_point3 origin, t_vector3 normal, int fov);

int				color_rgba(int r, int g, int b, int a);
int				color_rgba_struct(t_color color);
t_color			color_new(int hex);

t_camera		*camera_new_(t_point3 origin, t_vector3 target, int fov);
double			camera_position_x(size_t px);
double			camera_position_y(size_t py);
t_object		*object_new(char type, void *obj);
t_object		*plane_new(t_point3 cords, t_vector3 normal, t_color color);
t_object		*sphere_new(t_point3 center, double diameter, t_color color);

t_pixel			*pixel_new(double t, t_object *obj, t_mrt_ray *ray);
#endif
